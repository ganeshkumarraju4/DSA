# Write your MySQL query statement below
SELECT DISTINCT firstName, lastName,city,state FROM Person
LEFT JOIN Address
ON Person.personId = Address.personId;
