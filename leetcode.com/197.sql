# Write your MySQL query statement below
select w1.Id
from Weather w1
join Weather w2 on DATEDIFF(w1.RecordDate,w2.RecordDate) = 1
where w1.Temperature > w2.Temperature;
