WITH ranked_reviews AS (
    SELECT 
        employee_id,
        rating,
        ROW_NUMBER() OVER (PARTITION BY employee_id ORDER BY review_date DESC, review_id DESC) AS rn
    FROM performance_reviews
),
filtered_reviews AS (
    SELECT 
        employee_id,
        MAX(CASE WHEN rn = 1 THEN rating END) AS r1,
        MAX(CASE WHEN rn = 2 THEN rating END) AS r2,
        MAX(CASE WHEN rn = 3 THEN rating END) AS r3,
        COUNT(*) AS cnt
    FROM ranked_reviews
    WHERE rn <= 3
    GROUP BY employee_id
)
SELECT 
    e.employee_id,
    e.name,
    (f.r1 - f.r3) AS improvement_score
FROM filtered_reviews f
JOIN employees e ON e.employee_id = f.employee_id
WHERE f.cnt = 3
  AND f.r3 < f.r2
  AND f.r2 < f.r1
ORDER BY improvement_score DESC, e.name ASC;