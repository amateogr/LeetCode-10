SELECT product_id, store, price
FROM Products
CROSS JOIN LATERAL (
    VALUES ('store1', store1), ('store2', store2), ('store3', store3)
) AS t(store, price)
WHERE price IS NOT NULL;