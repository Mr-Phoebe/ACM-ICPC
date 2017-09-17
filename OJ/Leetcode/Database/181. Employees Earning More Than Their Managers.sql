# Write your MySQL query statement below
SELECT Name as Employee
FROM Employee as e
WHERE Salary > (SELECT Salary FROM Employee as e1 WHERE e1.Id = e.ManagerId)

'''
SELECT employer.Name
FROM  Employee employer INNER JOIN Employee manager ON (employer.ManagerId = manager.Id )
WHERE employer.Salary > manager.Salary ;
'''