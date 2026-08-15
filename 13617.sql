WITH student_history AS (
    SELECT 
        student_id,
        COUNT(*) AS total_sessions,
        SUM(hours_studied) AS total_study_hours,
        array_agg(subject ORDER BY session_date, session_id) AS subjects,
        MAX(session_date::date - prev_date::date) AS max_gap
    FROM (
        SELECT 
            session_id,
            student_id,
            subject,
            session_date,
            hours_studied,
            LAG(session_date) OVER (PARTITION BY student_id ORDER BY session_date, session_id) AS prev_date
        FROM study_sessions
    ) t
    GROUP BY student_id
),
valid_patterns AS (
    SELECT 
        sh.student_id,
        sh.total_study_hours,
        c.cycle_length
    FROM student_history sh
    CROSS JOIN LATERAL generate_series(3, sh.total_sessions / 2) AS c(cycle_length)
    WHERE sh.total_sessions >= 6 
      AND (sh.max_gap IS NULL OR sh.max_gap <= 2)
      AND sh.total_sessions % c.cycle_length = 0
      AND (
          SELECT count(DISTINCT sh.subjects[i]) 
          FROM generate_series(1, c.cycle_length) i
      ) = c.cycle_length
      AND (
          SELECT bool_and(sh.subjects[i] = sh.subjects[((i - 1) % c.cycle_length) + 1])
          FROM generate_series(1, sh.total_sessions) i
      )
)
SELECT 
    s.student_id,
    s.student_name,
    s.major,
    v.cycle_length,
    v.total_study_hours
FROM valid_patterns v
JOIN students s ON s.student_id = v.student_id
ORDER BY v.cycle_length DESC, v.total_study_hours DESC;