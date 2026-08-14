SELECT 
    content_id, 
    content_text AS original_text,
    (
        SELECT STRING_AGG(
            CASE 
                WHEN w ~ '^[a-zA-Z]+-[a-zA-Z]+$' THEN INITCAP(w)
                WHEN w ~ '^[a-zA-Z]' THEN UPPER(LEFT(w, 1)) || LOWER(SUBSTR(w, 2))
                ELSE LOWER(w)
            END, 
            ' ' ORDER BY ord
        )
        FROM unnest(string_to_array(content_text, ' ')) WITH ORDINALITY AS t(w, ord)
    ) AS converted_text
FROM 
    user_content;