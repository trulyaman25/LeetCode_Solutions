# Write your MySQL query statement below

SELECT 
    s.user_id,
    round(
        avg(
            if(c.action="confirmed",1,0)
        ),
    2) as confirmation_rate
FROM 
    Signups AS s
LEFT JOIN 
    Confirmations AS c
ON 
    c.user_id = s.user_id
GROUP BY 
    c.user_id;