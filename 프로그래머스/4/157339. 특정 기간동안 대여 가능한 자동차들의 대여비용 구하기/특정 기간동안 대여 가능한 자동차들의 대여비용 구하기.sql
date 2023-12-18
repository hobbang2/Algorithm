-- 코드를 입력하세요
WITH AVAILABLE_TBL AS (
    SELECT A.CAR_ID,
           A.START_DATE, A.END_DATE,
           CASE 
             -- 22년 11월 1일부터 22년 11월 30일까지..
             -- START DATE가 22년 11월 1일부터 11월 30일 사이 인것 
             -- 또는 START_DATE가 22년 11월 30일 이전이면서 END DATE가 22년 11월 1일 이후인 것
             WHEN START_DATE BETWEEN '22-11-01' AND '22-11-30' THEN 0
             -- 시작이 11월 30일 전이면서 끝이 11월 1일 이후인 경우 대여불가
             WHEN START_DATE < '22-12-01' AND END_DATE > '22-11-01' THEN 0
             ELSE 1
           END AS  AVAILABLE 
    FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY AS A
)



SELECT * 
FROM (
SELECT A.CAR_ID, A.CAR_TYPE, ROUND((A.DAILY_FEE * (1 -(C.DISCOUNT_RATE / 100))) * 30) AS FEE
FROM CAR_RENTAL_COMPANY_CAR  AS A, -- 대여 중인 자동차들의 정보
     CAR_RENTAL_COMPANY_DISCOUNT_PLAN AS C -- 테이블과 자동차 종류 별 대여 기간 종류 별 할인 정책 정보
WHERE   A.CAR_TYPE IN ('세단', 'SUV')
AND     A.CAR_TYPE = C.CAR_TYPE
AND     C.DURATION_TYPE = '30일 이상'
        -- 대여 불가 목록에 없는 차
AND     A.CAR_ID NOT IN (SELECT DISTINCT CAR_ID FROM AVAILABLE_TBL WHERE AVAILABLE = 0)
) AS Z
WHERE     FEE >= 500000 AND FEE < 2000000
ORDER BY FEE DESC, CAR_TYPE ASC , CAR_ID DESC

-- 세단 또는 SUV 이면서
-- 22년 11월 1일부터 22년 11월 30일까지 대여 가능
-- 30일간 대여 금액이 50만원 이상 200만원 미만인 자동차
-- ID, 종류, 대여 금액(FEE) 리스트 출력
-- 대여 금액 기준 내림차순 정렬,
-- 대여 금액이 같은 경우 자동차 종류 기준 오름차순 정렬,
-- 자동차 종류까지 같은 경우 자동차 ID 기준 내림차순 정렬