# Write your MySQL query statement below
with temp as (
select player_id, device_id,games_played ,event_date as first_login,row_number() over(
    partition by player_id
    order by event_date
) as rn from Activity
)
select player_id,first_login from temp
where rn = 1