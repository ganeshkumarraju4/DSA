# Write your MySQL query statement below
with temp as (
select user_id,count(user_id) over(
    partition by user_id
) as prompt_count,round(
avg(tokens) over(
    partition by user_id
) ,2) as avg_tokens
from prompts
)
, temp2 as (
    select p.user_id,t.prompt_count,
        t.avg_tokens from prompts p
    join temp t
    on p.user_id = t.user_id
    where p.tokens > t.avg_tokens and prompt_count>2
)
select distinct user_id,prompt_count,avg_tokens from temp2
order by avg_tokens desc,user_id asc