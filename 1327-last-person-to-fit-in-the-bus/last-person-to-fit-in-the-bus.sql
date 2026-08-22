# Write your MySQL query statement below
with sumw as
(
    SELECT person_id,person_name,SUM(weight) OVER (order by turn) as runs,turn
    FROM Queue
)
SELECT person_name from sumw
WHERE runs<=1000
ORDER BY turn DESC LIMIT 1;