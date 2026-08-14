WITH stats AS (
    SELECT 
        student_id,
        subject,
        MIN(exam_date) AS min_date,
        MAX(exam_date) AS max_date,
        COUNT(*) AS total_exams
    FROM Scores
    GROUP BY student_id, subject
    HAVING COUNT(*) >= 2
)
SELECT 
    s.student_id,
    s.subject,
    f.score AS first_score,
    l.score AS latest_score
FROM stats s
JOIN Scores f ON f.student_id = s.student_id AND f.subject = s.subject AND f.exam_date = s.min_date
JOIN Scores l ON l.student_id = s.student_id AND l.subject = s.subject AND l.exam_date = s.max_date
WHERE l.score > f.score
ORDER BY s.student_id, s.subject;