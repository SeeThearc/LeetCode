# Write your MySQL query statement below
with fyear as 
(
    SELECT product_id,MIN(year) as first_year
    FROM Sales
    GROUP BY product_id
)
SELECT f.product_id,f.first_year,s.quantity as quantity,s.price as price
FROM fyear f LEFT JOIN Sales s
ON f.product_id=s.product_id  and f.first_year = s.year;