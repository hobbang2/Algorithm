-- 코드를 작성해주세요
SELECT   YEAR(YM) AS YEAR,
         ROUND(AVG(PM_VAL1), 2) AS 'PM10',
         ROUND(AVG(PM_VAL2), 2) AS 'PM2.5'
FROM     AIR_POLLUTION
WHERE    LOCATION2 LIKE '수원%'
GROUP BY YEAR
ORDER BY YEAR ASC;
-- 수원 지역의 연도별 평균 미세먼지 오염도
-- 평균 초미세먼지 오염도 조회
-- 소수 셋째 자리 반올림
-- 연도 기준 오름차순