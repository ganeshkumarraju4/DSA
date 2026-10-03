WITH temp AS (
    SELECT
        user_id,
        COUNT(user_id) OVER(PARTITION BY user_id) AS prompt_count,
        ROUND(
            AVG(tokens) OVER(PARTITION BY user_id),
            2
        ) AS avg_tokens
    FROM prompts
),
temp2 AS (
    SELECT
        p.user_id,
        t.prompt_count,
        t.avg_tokens
    FROM prompts p
    JOIN temp t
        ON p.user_id = t.user_id
    WHERE p.tokens > t.avg_tokens and prompt_count > 2
)
SELECT DISTINCT
    user_id,
    prompt_count,
    avg_tokens
FROM temp2
ORDER BY avg_tokens DESC, user_id ASC;