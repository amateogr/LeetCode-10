WITH user_stats AS (
    SELECT 
        user_id,
        COUNT(*) AS prompt_count,
        AVG(tokens) AS avg_tokens
    FROM prompts
    GROUP BY user_id
    HAVING COUNT(*) >= 3
)
SELECT 
    user_id,
    prompt_count,
    ROUND(avg_tokens, 2) AS avg_tokens
FROM user_stats
WHERE EXISTS (
    SELECT 1 
    FROM prompts 
    WHERE prompts.user_id = user_stats.user_id 
      AND prompts.tokens > user_stats.avg_tokens
)
ORDER BY avg_tokens DESC, user_id ASC;