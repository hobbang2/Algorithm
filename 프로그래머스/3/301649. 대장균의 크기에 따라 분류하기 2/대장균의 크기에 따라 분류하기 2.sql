-- 대장균 개체의 크기를 내림차순 정렬
-- 상위 0% ~ 25% CRITICAL
-- 26 ~ 50 HIGH
-- 51 ~ 75 MEDIUM
-- 76 ~ 100 LOW
-- 대장균 개체의 ID와 분류된 이름을 출력하는 SQL문
-- ID에 대해 오름차순 정렬 
-- 같은 사이즈의 대중균 개체가 서로 다른 이름으로 분류되는 경우는 없음

SELECT ID,
       CASE
            WHEN TOP_PERCENT <= 25 THEN 'CRITICAL'
            WHEN TOP_PERCENT <= 50 THEN 'HIGH'
            WHEN TOP_PERCENT <= 75 THEN 'MEDIUM'
            ELSE  'LOW'
       END AS 'COLONY_NAME'
FROM (
SELECT      ID, SIZE_OF_COLONY, 
            ROUND(PERCENT_RANK() OVER (ORDER BY SIZE_OF_COLONY DESC) * 100, 2 ) AS TOP_PERCENT
FROM        ECOLI_DATA
ORDER BY    SIZE_OF_COLONY DESC) AS A
ORDER BY ID ASC