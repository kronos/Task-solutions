# Write your MySQL query statement below
select e1.Name as Employee
from Employee e1
join Employee e2 on e1.ManagerId = e2.Id
where e2.Salary < e1.Salary;
