SELECT ip, COUNT(*) AS invalid_count
FROM logs
WHERE 
    length(ip) - length(replace(ip, '.', '')) != 3
    OR ip ~ '(^|\.)(0[0-9]+|25[6-9]|2[6-9][0-9]|[3-9][0-9]{2}|[0-9]{4,})(\.|$)'
GROUP BY ip
ORDER BY invalid_count DESC, ip DESC;