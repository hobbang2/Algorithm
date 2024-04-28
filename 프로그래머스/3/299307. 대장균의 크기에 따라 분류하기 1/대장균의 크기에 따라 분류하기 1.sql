-- 코드를 작성해주세요
-- 개체의 크기에 따라 분류 결과 출력, ID에 대해 오름차순 정렬

SELECT      ID,
            CASE
                WHEN SIZE_OF_COLONY <= 100 THEN 'LOW'
                WHEN SIZE_OF_COLONY <= 1000 THEN 'MEDIUM'
            ELSE 'HIGH'
            END AS 'SIZE'
FROM        ECOLI_DATA
ORDER BY    ID