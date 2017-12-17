# Write your MySQL query statement below
SELECT dep.Name AS Department, emp.Name AS Employee, emp.Salary FROM Department dep,
Employee emp WHERE emp.DepartmentId=dep.Id AND
(SELECT COUNT(distinct Salary) FROM Employee WHERE DepartmentId=dep.Id AND Salary>emp.Salary)<3
