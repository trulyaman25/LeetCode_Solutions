# Write your MySQL query statement below

SELECT unique_id, name
FROM Employees AS e
LEFT JOIN EmployeeUNI as u
ON e.id = u.id