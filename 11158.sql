SELECT 
    u.user_id AS buyer_id,
    u.join_date,
    COALESCE(o.orders_count, 0) AS orders_in_2019
FROM Users u
LEFT JOIN (
    SELECT 
        buyer_id, 
        COUNT(*) AS orders_count
    FROM Orders
    WHERE order_date >= '2019-01-01' 
      AND order_date <= '2019-12-31'
    GROUP BY buyer_id
) o ON u.user_id = o.buyer_id;