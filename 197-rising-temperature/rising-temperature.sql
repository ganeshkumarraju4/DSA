# Write your MySQL query statement below
SELECT w.id as Id from Weather w
join Weather w2 
on w.recordDate = DATE_ADD(w2.recordDate, INTERVAL 1 day) and w.temperature > w2.temperature
