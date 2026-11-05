# Write your MySQL query statement below
with temp as (
    select num,count(num) as cnt from MyNumbers
    group by num
)
select case when cnt=1 then num else null end as num from temp
order by num desc
limit 1