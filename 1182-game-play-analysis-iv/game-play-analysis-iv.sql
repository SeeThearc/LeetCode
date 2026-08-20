# Write your MySQL query statement below
with firstlogin as 
(
    select player_id,MIN(event_date) as ilogin
    FROM Activity
    GROUP BY player_id
)
SELECT ROUND(COUNT(a.player_id)/COUNT(f.player_id),2) as fraction
FROM firstlogin f LEFT JOIN Activity a
ON f.player_id=a.player_id
AND a.event_date = DATE_ADD(f.ilogin,INTERVAL 1 DAY);