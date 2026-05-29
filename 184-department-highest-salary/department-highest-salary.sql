# Write your MySQL query statement below
WITH temp AS (
   SELECT e.name AS Employee,
           e.salary,
           d.name AS Department
    FROM Employee e
    JOIN Department d
    ON e.departmentId = d.id
),
maxDeptSalary As (
    SELECT Department,
           MAX(salary) AS max_salary
    FROM temp
    GROUP BY Department
)
SELECT t.Department,
       t.Employee,
       t.salary AS Salary
FROM temp t
JOIN maxDeptSalary m
ON t.Department = m.Department
AND t.salary = m.max_salary;