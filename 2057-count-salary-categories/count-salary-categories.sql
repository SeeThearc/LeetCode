# Write your MySQL query statement below
SELECT 'Low Salary' as category,
    SUM(CASE WHEN income<20000 THEN 1 ELSE 0 END) as accounts_count
FROM Accounts
UNION ALL
SELECT 'Average Salary' as category,
    SUM(CASE WHEN income between 20000 and 50000 THEN 1 ELSE 0 END) as accounts_count
FROM Accounts
UNION ALL
SELECT 'High Salary' as category,
    SUM(CASE WHEN income>50000 THEN 1 ELSE 0 END) as accounts_count
FROM Accounts;