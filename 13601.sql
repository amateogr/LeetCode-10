WITH driver_metrics AS (
    SELECT 
        driver_id,
        AVG(CASE WHEN EXTRACT(MONTH FROM trip_date) <= 6 THEN distance_km / fuel_consumed END) AS first_half_avg,
        AVG(CASE WHEN EXTRACT(MONTH FROM trip_date) > 6 THEN distance_km / fuel_consumed END) AS second_half_avg
    FROM trips
    GROUP BY driver_id
)
SELECT 
    d.driver_id,
    d.driver_name,
    ROUND(dm.first_half_avg, 2) AS first_half_avg,
    ROUND(dm.second_half_avg, 2) AS second_half_avg,
    ROUND(dm.second_half_avg - dm.first_half_avg, 2) AS efficiency_improvement
FROM driver_metrics dm
JOIN drivers d ON d.driver_id = dm.driver_id
WHERE dm.first_half_avg IS NOT NULL 
  AND dm.second_half_avg IS NOT NULL
  AND dm.second_half_avg > dm.first_half_avg
ORDER BY efficiency_improvement DESC, d.driver_name ASC;