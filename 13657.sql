SELECT customer_id
FROM customer_transactions
GROUP BY customer_id
HAVING 
    COUNT(*) FILTER (WHERE transaction_type = 'purchase') >= 3
    AND (MAX(transaction_date) - MIN(transaction_date)) >= 30
    AND (COUNT(*) FILTER (WHERE transaction_type = 'refund')::numeric / COUNT(*)) < 0.2
ORDER BY customer_id;