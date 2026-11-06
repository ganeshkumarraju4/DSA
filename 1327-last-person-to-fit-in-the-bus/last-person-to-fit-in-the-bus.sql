# Write your MySQL query statement below
with temp as (
    select * , sum(weight) over(order by turn ) as currWeight from Queue
    order by turn asc
)
select person_name from temp
where currWeight<=1000
order by currWeight desc
limit 1