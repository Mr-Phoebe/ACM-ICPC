# Write your MySQL query statement below  
SELECT t.Department, p.Name AS Employee, t.Salary FROM Employee AS p,  
(SELECT d.Id,d.Name AS Department,MAX(e.Salary) AS Salary FROM Department AS d   
INNER JOIN Employee AS e ON d.Id = e.DepartmentId GROUP BY e.DepartmentId) AS t   
WHERE p.Salary = t.Salary AND p.DepartmentId = t.Id;  
