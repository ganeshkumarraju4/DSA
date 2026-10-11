# Write your MySQL query statement below
with temp as (
    select a1.machine_id,a1.process_id,a1.timestamp-a2.timestamp as diff from Activity a1
    join Activity a2
    on a1.machine_id = a2.machine_id and a1.process_id = a2.process_id and a1.activity_type = 'end' and a2.activity_type = 'start'
)
select machine_id,round(avg(diff),3) as processing_time from temp
group by machine_id