# Write your MySQL query statement below
SELECT e1.name
FROM Employee as e1
JOIN Employee as e2
ON e1.id != e2.managerId OR e2.managerId IS NOT NULL
GROUP BY e2.managerId;