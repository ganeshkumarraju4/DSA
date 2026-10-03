WITH first_positive AS (
    SELECT
        patient_id,
        MIN(test_date) AS positive_date
    FROM covid_tests
    WHERE result = 'Positive'
    GROUP BY patient_id
),
first_negative AS (
    SELECT
        t.patient_id,
        MIN(t.test_date) AS negative_date
    FROM covid_tests t
    JOIN first_positive p
        ON t.patient_id = p.patient_id
    WHERE t.result = 'Negative'
      AND t.test_date > p.positive_date
    GROUP BY t.patient_id
)
SELECT
    p.patient_id,
    p.patient_name,
    p.age,
    DATEDIFF(n.negative_date, fp.positive_date) AS recovery_time
FROM patients p
JOIN first_positive fp
    ON p.patient_id = fp.patient_id
JOIN first_negative n
    ON p.patient_id = n.patient_id
ORDER BY recovery_time ASC, p.patient_name ASC;