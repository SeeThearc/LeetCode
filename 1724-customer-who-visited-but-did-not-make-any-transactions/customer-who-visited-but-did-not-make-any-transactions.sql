# Write your MySQL query statement below
SELECT customer_id,COUNT(v1.visit_id) as count_no_trans
FROM Visits v1 LEFT JOIN Transactions t1 ON v1.visit_id=t1.visit_id
WHERE transaction_id is NULL
GROUP BY customer_id;