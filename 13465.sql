SELECT product_id, product_name, description
FROM products
WHERE description ~ '(?:^|[^a-zA-Z0-9])SN[0-9]{4}-[0-9]{4}(?:[^a-zA-Z0-9]|$)'
ORDER BY product_id;