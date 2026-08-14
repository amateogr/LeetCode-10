WITH user_stats AS (
    SELECT
        user_id,
        reaction,
        COUNT(*) AS reaction_count,
        SUM(COUNT(*)) OVER (PARTITION BY user_id) AS total_reactions
    FROM reactions
    GROUP BY user_id, reaction
),
ranked_reactions AS (
    SELECT
        user_id,
        reaction AS dominant_reaction,
        ROUND(reaction_count::numeric / total_reactions, 2) AS reaction_ratio,
        ROW_NUMBER() OVER (PARTITION BY user_id ORDER BY reaction_count DESC, reaction ASC) AS rn
    FROM user_stats
    WHERE total_reactions >= 5
)
SELECT
    user_id,
    dominant_reaction,
    reaction_ratio
FROM ranked_reactions
WHERE rn = 1 AND reaction_ratio >= 0.60
ORDER BY reaction_ratio DESC, user_id ASC;