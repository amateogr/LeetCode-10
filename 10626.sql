SELECT 
    CASE 
        WHEN id % 2 != 0 AND id = counts THEN id
        WHEN id % 2 != 0 THEN id + 1
        ELSE id - 1
    END AS id,
    student
FROM Seat, (SELECT COUNT(*) AS counts FROM Seat) AS seat_counts
ORDER BY id;