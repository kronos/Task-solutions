# Write your MySQL query statement below
select Name as Customers
from Customers
left join Orders on Orders.CustomerId = Customers.id
where Orders.Id is null;
