WITH weekly_meetings AS (
    SELECT
        employee_id,
        date_trunc('week', meeting_date) AS week_start,
        SUM(duration_hours) AS total_hours
    FROM meetings
    GROUP BY employee_id, date_trunc('week', meeting_date)
    HAVING SUM(duration_hours) > 20
),
qualified_employees AS (
    SELECT
        employee_id,
        COUNT(*) AS meeting_heavy_weeks
    FROM weekly_meetings
    GROUP BY employee_id
    HAVING COUNT(*) >= 2
)
SELECT
    e.employee_id,
    e.employee_name,
    e.department,
    q.meeting_heavy_weeks
FROM qualified_employees q
JOIN employees e USING (employee_id)
ORDER BY q.meeting_heavy_weeks DESC, e.employee_name ASC;