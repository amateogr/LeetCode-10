WITH RECURSIVE 
lvl AS (
    SELECT employee_id, 1 AS level 
    FROM Employees 
    WHERE manager_id IS NULL
    UNION ALL
    SELECT e.employee_id, l.level + 1 
    FROM Employees e
    JOIN lvl l ON e.manager_id = l.employee_id
),
sub AS (
    SELECT employee_id AS ancestor_id, employee_id AS descendant_id, salary 
    FROM Employees
    UNION ALL
    SELECT s.ancestor_id, e.employee_id, e.salary 
    FROM sub s
    JOIN Employees e ON s.descendant_id = e.manager_id
)
SELECT 
    e.employee_id,
    e.employee_name,
    l.level,
    COUNT(s.descendant_id) - 1 AS team_size,
    SUM(s.salary) AS budget
FROM Employees e
JOIN lvl l ON e.employee_id = l.employee_id
JOIN sub s ON e.employee_id = s.ancestor_id
GROUP BY e.employee_id, e.employee_name, l.level
ORDER BY l.level ASC, budget DESC, e.employee_name ASC;