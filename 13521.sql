WITH co_purchases AS (
    SELECT 
        a.product_id AS product1_id,
        b.product_id AS product2_id,
        COUNT(a.user_id) AS customer_count
    FROM ProductPurchases a
    JOIN ProductPurchases b 
        ON a.user_id = b.user_id 
        AND a.product_id < b.product_id
    GROUP BY a.product_id, b.product_id
    HAVING COUNT(a.user_id) >= 3
)
SELECT 
    c.product1_id,
    c.product2_id,
    i1.category AS product1_category,
    i2.category AS product2_category,
    c.customer_count
FROM co_purchases c
JOIN ProductInfo i1 ON c.product1_id = i1.product_id
JOIN ProductInfo i2 ON c.product2_id = i2.product_id
ORDER BY c.customer_count DESC, c.product1_id ASC, c.product2_id ASC;