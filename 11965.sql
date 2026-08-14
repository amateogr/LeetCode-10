SELECT COALESCE(e.employee_id, s.employee_id) AS employee_id
FROM Employees e
FULL OUTER JOIN Salaries s USING (employee_id)
WHERE e.name IS NULL OR s.salary IS NULL
ORDER BY employee_id;