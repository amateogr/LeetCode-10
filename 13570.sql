WITH active_borrowers AS (
    SELECT book_id, COUNT(*) AS current_borrowers
    FROM borrowing_records
    WHERE return_date IS NULL
    GROUP BY book_id
)
SELECT 
    b.book_id,
    b.title,
    b.author,
    b.genre,
    b.publication_year,
    ab.current_borrowers
FROM library_books b
JOIN active_borrowers ab ON b.book_id = ab.book_id
WHERE b.total_copies = ab.current_borrowers
ORDER BY ab.current_borrowers DESC, b.title ASC;