WITH categorized_sales AS (
    SELECT 
        CASE 
            WHEN EXTRACT(MONTH FROM s.sale_date) IN (12, 1, 2) THEN 'Winter'
            WHEN EXTRACT(MONTH FROM s.sale_date) BETWEEN 3 AND 5 THEN 'Spring'
            WHEN EXTRACT(MONTH FROM s.sale_date) BETWEEN 6 AND 8 THEN 'Summer'
            ELSE 'Fall'
        END AS season,
        p.category,
        SUM(s.quantity) AS total_quantity,
        SUM(s.quantity * s.price) AS total_revenue
    FROM sales s
    JOIN products p USING (product_id)
    GROUP BY 1, 2
),
ranked_sales AS (
    SELECT 
        season,
        category,
        total_quantity,
        total_revenue,
        ROW_NUMBER() OVER (
            PARTITION BY season 
            ORDER BY total_quantity DESC, total_revenue DESC, category ASC
        ) AS rn
    FROM categorized_sales
)
SELECT 
    season,
    category,
    total_quantity,
    total_revenue
FROM ranked_sales
WHERE rn = 1
ORDER BY season;