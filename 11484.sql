SELECT 
    sell_date,
    COUNT(product) AS num_sold,
    GROUP_CONCAT(product ORDER BY product SEPARATOR ',') AS products
FROM (
    SELECT DISTINCT sell_date, product 
    FROM Activities
) AS t
GROUP BY sell_date
ORDER BY sell_date;