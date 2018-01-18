# Write your MySQL query statement below
select w1.Id from Weather w1, Weather w2 
where TO_DAYS(w1.Date)=TO_DAYS(w2.Date)+1 and w1.Temperature>w2.Temperature;
