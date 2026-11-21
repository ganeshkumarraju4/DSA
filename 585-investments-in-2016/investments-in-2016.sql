# Write your MySQL query statement below
WITH temp AS (
    SELECT i.pid, i.tiv_2015, i.tiv_2016
    FROM Insurance i
    JOIN (
        SELECT lat, lon
        FROM Insurance
        GROUP BY lat, lon
        HAVING COUNT(*) = 1
    ) unique_locations
    ON i.lat = unique_locations.lat
    AND i.lon = unique_locations.lon
),
t as (
    select tiv_2015 from Insurance
    group by tiv_2015
    having count(tiv_2016) > 1
)
select round(sum(temp.tiv_2016),2) as tiv_2016 from temp
join t on temp.tiv_2015 = t.tiv_2015