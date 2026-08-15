SELECT 
    session_id,
    user_id,
    (EXTRACT(EPOCH FROM (MAX(event_timestamp) - MIN(event_timestamp))) / 60)::integer AS session_duration_minutes,
    COUNT(*) FILTER (WHERE event_type = 'scroll') AS scroll_count
FROM app_events
GROUP BY session_id, user_id
HAVING 
    MAX(event_timestamp) - MIN(event_timestamp) > INTERVAL '30 minutes'
    AND COUNT(*) FILTER (WHERE event_type = 'scroll') >= 5
    AND COUNT(*) FILTER (WHERE event_type = 'click')::numeric / NULLIF(COUNT(*) FILTER (WHERE event_type = 'scroll'), 0) < 0.20
    AND COUNT(*) FILTER (WHERE event_type = 'purchase') = 0
ORDER BY scroll_count DESC, session_id ASC;