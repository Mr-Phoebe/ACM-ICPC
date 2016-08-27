# Write your MySQL query statement below
select c.Name as Customers
from Customers c
where (select count(*) from Orders o where o.customerId=c.id)=0