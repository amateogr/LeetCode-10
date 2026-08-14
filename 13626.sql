WITH ranked AS (
    SELECT 
        store_id,
        product_name,
        quantity,
        price,
        ROW_NUMBER() OVER (PARTITION BY store_id ORDER BY price DESC, product_name ASC) AS rn_desc,
        ROW_NUMBER() OVER (PARTITION BY store_id ORDER BY price ASC, product_name ASC) AS rn_asc,
        COUNT(*) OVER (PARTITION BY store_id) AS total_products
    FROM inventory
),
store_bounds AS (
    SELECT 
        store_id,
        MAX(CASE WHEN rn_desc = 1 THEN product_name END) AS most_exp_product,
        MAX(CASE WHEN rn_desc = 1 THEN quantity END) AS most_exp_qty,
        MAX(CASE WHEN rn_asc = 1 THEN product_name END) AS cheapest_product,
        MAX(CASE WHEN rn_asc = 1 THEN quantity END) AS cheapest_qty,
        MAX(total_products) AS total_products
    FROM ranked
    GROUP BY store_id
    HAVING MAX(total_products) >= 3
)
SELECT 
    s.store_id,
    s.store_name,
    s.location,
    b.most_exp_product,
    b.cheapest_product,
    ROUND((b.cheapest_qty::numeric / b.most_exp_qty), 2) AS imbalance_ratio
FROM store_bounds b
JOIN stores s ON s.store_id = b.store_id
WHERE b.cheapest_qty > b.most_exp_qty
ORDER BY imbalance_ratio DESC, s.store_name ASC;