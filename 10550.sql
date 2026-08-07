SELECT 
    ROUND(COUNT(DISTINCT CASE WHEN event_date = DATE_ADD(first_login, INTERVAL 1 DAY) THEN player_id END) / COUNT(DISTINCT player_id), 2) AS fraction
FROM (
    SELECT player_id, event_date, MIN(event_date) OVER (PARTITION BY player_id) AS first_login
    FROM Activity
) t;