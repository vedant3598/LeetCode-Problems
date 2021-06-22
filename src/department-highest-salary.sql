# Write your MySQL query statement below
SELECT Department.Name AS 'Department', Employee.Name AS 'Employee', Salary AS 'Salary' 
FROM Employee 
INNER JOIN Department ON Department.Id = Employee.DepartmentId 
WHERE (Employee.DepartmentId, Employee.Salary) 
    IN (SELECT Employee.DepartmentId, MAX(Employee.Salary) FROM Employee
        GROUP BY DepartmentId);
