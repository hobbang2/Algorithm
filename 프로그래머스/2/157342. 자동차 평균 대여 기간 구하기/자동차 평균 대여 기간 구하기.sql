-- 코드를 입력하세요
# SELECT TIMESTAMPDIFF(DAY, START_DATE, END_DATE) , DATEDIFF(END_DATE, START_DATE ), A.*
# FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY AS A 
# LIMIT 

WITH RENTAL_DURATION_TBL AS(
    SELECT A.CAR_ID,
           TIMESTAMPDIFF(DAY, A.START_DATE, A.END_DATE) + 1 AS TIME_DURATION
    FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY AS A
)

SELECT B.CAR_ID, ROUND(AVG(B.TIME_DURATION),1) AS AVERAGE_DURATION
FROM RENTAL_DURATION_TBL AS B
GROUP BY CAR_ID 
HAVING ROUND(AVG(B.TIME_DURATION),1) >= 7
ORDER BY AVERAGE_DURATION DESC , CAR_ID DESC

# SELECT CAR_ID, SUM(TIME_DURATION), COUNT(*)
# FROM RENTAL_DURATION_TBL
# GROUP BY CAR_ID 
# ORDER BY CAR_ID