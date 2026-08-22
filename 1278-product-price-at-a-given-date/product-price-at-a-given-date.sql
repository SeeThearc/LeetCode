# Write your MySQL query statement below
with latestdate as 
(
    SELECT product_id,MAX(change_date) as ltd
    FROM Products 
    WHERE change_date<= '2019-08-16'
    GROUP BY product_id
),
allid as
(
    SELECT DISTINCT product_id
    FROM Products
)
SELECT a.product_id,COALESCE(p.new_price,10) as price
FROM allid a LEFT JOIN latestdate l
ON a.product_id=l.product_id
LEFT JOIN Products p
ON p.product_id=l.product_id
AND p.change_date=l.ltd;