WITH user_metrics AS (
    SELECT
        user_id,
        MAX(monthly_amount) AS max_historical_amount,
        BOOL_OR(event_type = 'downgrade') AS has_downgrade,
        MIN(event_date) AS first_date,
        MAX(event_date) AS last_date
    FROM subscription_events
    GROUP BY user_id
),
latest_events AS (
    SELECT DISTINCT ON (user_id)
        user_id,
        plan_name AS current_plan,
        monthly_amount AS current_monthly_amount,
        event_type AS last_event_type
    FROM subscription_events
    ORDER BY user_id, event_date DESC, event_id DESC
)
SELECT
    m.user_id,
    l.current_plan,
    l.current_monthly_amount,
    m.max_historical_amount,
    (m.last_date - m.first_date) AS days_as_subscriber
FROM user_metrics m
JOIN latest_events l ON m.user_id = l.user_id
WHERE l.last_event_type != 'cancel'
  AND m.has_downgrade = TRUE
  AND l.current_monthly_amount < (m.max_historical_amount * 0.5)
  AND (m.last_date - m.first_date) >= 60
ORDER BY days_as_subscriber DESC, m.user_id ASC;