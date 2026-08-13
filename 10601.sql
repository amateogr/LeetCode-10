WITH ranked_stadium AS (
    SELECT id, visit_date, people,
           id - ROW_NUMBER() OVER (ORDER BY id) AS grp
    FROM Stadium
    WHERE people >= 100
),
validated_stadium AS (
    SELECT id, visit_date, people,
           COUNT(*) OVER (PARTITION BY grp) AS consecutive_count
    FROM ranked_stadium
)
SELECT id, visit_date, people
FROM validated_stadium
WHERE consecutive_count >= 3
ORDER BY visit_date ASC;