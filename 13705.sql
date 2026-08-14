WITH processed_orders AS (
    SELECT 
        customer_id,
        order_rating,
        CASE 
            WHEN (order_timestamp::time >= '11:00:00' AND order_timestamp::time <= '14:00:00') 
              OR (order_timestamp::time >= '18:00:00' AND order_timestamp::time <= '21:00:00') 
            THEN 1 
            ELSE 0 
        END AS is_peak
    FROM restaurant_orders
),
aggregated_customers AS (
    SELECT 
        customer_id,
        COUNT(*) AS total_orders,
        SUM(is_peak) AS peak_orders,
        COUNT(order_rating) AS rated_orders,
        AVG(order_rating) AS average_rating
    FROM processed_orders
    GROUP BY customer_id
)
SELECT 
    customer_id,
    total_orders,
    ROUND(100.0 * peak_orders / total_orders)::int AS peak_hour_percentage,
    ROUND(average_rating, 2) AS average_rating
FROM aggregated_customers
WHERE total_orders >= 3
  AND (peak_orders::numeric / total_orders) >= 0.6
  AND (rated_orders::numeric / total_orders) >= 0.5
  AND ROUND(average_rating, 2) >= 4.0
ORDER BY average_rating DESC, customer_id DESC;