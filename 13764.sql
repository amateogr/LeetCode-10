WITH top_students AS (
    SELECT user_id
    FROM course_completions
    GROUP BY user_id
    HAVING COUNT(*) >= 5 AND AVG(course_rating) >= 4.0
),
course_transitions AS (
    SELECT 
        c.course_name AS first_course,
        LEAD(c.course_name) OVER (PARTITION BY c.user_id ORDER BY c.completion_date, c.course_id) AS second_course
    FROM course_completions c
    JOIN top_students t ON c.user_id = t.user_id
)
SELECT 
    first_course,
    second_course,
    COUNT(*) AS transition_count
FROM course_transitions
WHERE second_course IS NOT NULL
GROUP BY first_course, second_course
ORDER BY transition_count DESC, LOWER(first_course) ASC, LOWER(second_course) ASC;