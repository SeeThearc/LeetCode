# Write your MySQL query statement below
SELECT a.user_id,ROUND(AVG(
    CASE
        WHEN c.action='confirmed' THEN 1.00
        ELSE 0
    END
    #if(c.action='confirmed',1.00,0)
),2) as confirmation_rate
FROM Signups a LEFT JOIN Confirmations c
ON a.user_id=c.user_id
GROUP BY a.user_id;