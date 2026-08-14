WITH first_pos AS (
    SELECT patient_id, MIN(test_date) AS pos_date
    FROM covid_tests
    WHERE result = 'Positive'
    GROUP BY patient_id
),
first_neg_after AS (
    SELECT f.patient_id, MIN(t.test_date) AS neg_date
    FROM first_pos f
    JOIN covid_tests t ON f.patient_id = t.patient_id
    WHERE t.result = 'Negative' AND t.test_date > f.pos_date
    GROUP BY f.patient_id
)
SELECT p.patient_id, p.patient_name, p.age, (n.neg_date - f.pos_date) AS recovery_time
FROM first_pos f
JOIN first_neg_after n ON f.patient_id = n.patient_id
JOIN patients p ON f.patient_id = p.patient_id
ORDER BY recovery_time ASC, p.patient_name ASC;