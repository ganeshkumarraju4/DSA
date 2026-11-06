# Write your MySQL query statement below
select e.employee_id,e.department_id from Employee e
join (
    select employee_id,count(department_id) as cnt from Employee
    group by employee_id
) e2
on e.employee_id = e2.employee_id
where e.primary_flag = 'Y' or e2.cnt = 1