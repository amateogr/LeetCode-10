WITH Daily AS (
    SELECT visited_on, SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
),
Windowed AS (
    SELECT 
        visited_on,
        SUM(amount) OVER w AS amount,
        ROUND(AVG(amount) OVER w, 2) AS average_amount,
        ROW_NUMBER() OVER (ORDER BY visited_on) AS rn
    FROM Daily
    WINDOW w AS (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW)
)
SELECT visited_on, amount, average_amount
FROM Windowed
WHERE rn >= 7;