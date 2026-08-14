WITH book_stats AS (
    SELECT 
        book_id,
        COUNT(*) AS total_sessions,
        MIN(session_rating) AS min_rating,
        MAX(session_rating) AS max_rating,
        SUM(CASE WHEN session_rating <= 2 OR session_rating >= 4 THEN 1 ELSE 0 END) AS extreme_count
    FROM reading_sessions
    GROUP BY book_id
    HAVING COUNT(*) >= 5 
       AND BOOL_OR(session_rating >= 4) 
       AND BOOL_OR(session_rating <= 2)
       AND (SUM(CASE WHEN session_rating <= 2 OR session_rating >= 4 THEN 1 ELSE 0 END)::numeric / COUNT(*)) >= 0.6
)
SELECT 
    b.book_id,
    b.title,
    b.author,
    b.genre,
    b.pages,
    (bs.max_rating - bs.min_rating) AS rating_spread,
    ROUND(bs.extreme_count::numeric / bs.total_sessions, 2) AS polarization_score
FROM book_stats bs
JOIN books b ON bs.book_id = b.book_id
ORDER BY polarization_score DESC, b.title DESC;