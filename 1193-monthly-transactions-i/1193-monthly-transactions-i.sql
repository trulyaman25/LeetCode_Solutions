# Write your MySQL query statement below

SELECT
    LEFT(trans_date, 7) as month,
    country,
    COUNT(id) AS trans_count,
    SUM(state = 'approved') AS approved_count,
    SUM(amount) AS trans_total_amount,
    SUM((state = 'approved') * amount) AS approved_total_amount
FROM 
    transactions
GROUP BY
    month, country