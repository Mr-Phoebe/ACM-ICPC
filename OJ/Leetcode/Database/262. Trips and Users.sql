# Write your MySQL query statement below
select Request_at as 'Day', ROUND(COUNT(if(a.`Status` <> 'completed',1,null))/COUNT(*),2) as 'Cancellation Rate'
from Trips a
inner join Users b on a.Client_Id=b.Users_Id and b.Role='client'
where b.Banned='No' and a.Request_at>='2013-10-01' and a.Request_at<='2013-10-03'
group by a.Request_at