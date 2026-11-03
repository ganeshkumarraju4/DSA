# Write your MySQL query statement below
with temp as(
    SELECT customer_id, delivery_id, order_date, customer_pref_delivery_date
FROM (
    SELECT *, 
           ROW_NUMBER() OVER (PARTITION BY customer_id ORDER BY order_date ASC) AS rn
    FROM Delivery
) t
WHERE rn = 1
)
select round(sum(case when order_date =customer_pref_delivery_date then 1 else 0 end )*100/count(customer_id),2) as immediate_percentage
from temp;