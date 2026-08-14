SELECT 
    stock_name,
    SUM(price) FILTER (WHERE operation = 'Sell') - SUM(price) FILTER (WHERE operation = 'Buy') AS capital_gain_loss
FROM 
    Stocks
GROUP BY 
    stock_name;