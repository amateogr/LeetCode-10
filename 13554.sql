WITH customer_categories AS (
    SELECT DISTINCT p.user_id, i.category
    FROM ProductPurchases p
    JOIN ProductInfo i ON p.product_id = i.product_id
)
SELECT 
    c1.category AS category1,
    c2.category AS category2,
    COUNT(*) AS customer_count
FROM customer_categories c1
JOIN customer_categories c2 ON c1.user_id = c2.user_id AND c1.category < c2.category
GROUP BY c1.category, c2.category
HAVING COUNT(*) >= 3
ORDER BY customer_count DESC, category1 ASC, category2 ASC;