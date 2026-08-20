# Write your MySQL query statement below
WITH csub AS
(
    SELECT class,COUNT(student) as cou
    FROM Courses 
    GROUP BY class
)
SELECT class 
FROM csub 
WHERE cou>=5;