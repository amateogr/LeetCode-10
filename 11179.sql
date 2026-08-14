SELECT 
    id,
    MAX(revenue) FILTER (WHERE month = 'Jan') AS Jan_Revenue,
    MAX(revenue) FILTER (WHERE month = 'Feb') AS Feb_Revenue,
    MAX(revenue) FILTER (WHERE month = 'Mar') AS Mar_Revenue,
    MAX(revenue) FILTER (WHERE month = 'Apr') AS Apr_Revenue,
    MAX(revenue) FILTER (WHERE month = 'May') AS May_Revenue,
    MAX(revenue) FILTER (WHERE month = 'Jun') AS Jun_Revenue,
    MAX(revenue) FILTER (WHERE month = 'Jul') AS Jul_Revenue,
    MAX(revenue) FILTER (WHERE month = 'Aug') AS Aug_Revenue,
    MAX(revenue) FILTER (WHERE month = 'Sep') AS Sep_Revenue,
    MAX(revenue) FILTER (WHERE month = 'Oct') AS Oct_Revenue,
    MAX(revenue) FILTER (WHERE month = 'Nov') AS Nov_Revenue,
    MAX(revenue) FILTER (WHERE month = 'Dec') AS Dec_Revenue
FROM Department
GROUP BY id;