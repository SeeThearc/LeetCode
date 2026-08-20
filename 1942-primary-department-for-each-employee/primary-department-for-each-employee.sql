# Write your MySQL query statement below
with dptcount AS
(
    SELECT employee_id,COUNT(department_id) as dcou
    FROM Employee
    GROUP BY employee_id
)
SELECT d.employee_id,e.department_id
FROM dptcount d LEFT JOIN Employee e
ON d.employee_id=e.employee_id
AND
    CASE
        WHEN d.dcou>1 THEN e.primary_flag='Y'
        ELSE TRUE
    END;