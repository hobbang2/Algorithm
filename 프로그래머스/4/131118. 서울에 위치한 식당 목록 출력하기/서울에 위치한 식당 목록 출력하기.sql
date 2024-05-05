-- 코드를 입력하세요

-- 서울에 위치한 식당들의 식당 ID, 식당 이름, 음식 종류, 즐겨찾기수, 주소, 리뷰 평균 점수를 조회하는 SQL문을 작성해주세요. 이때 리뷰 평균점수는 소수점 세 번째 자리에서 반올림 해주시고 결과는 평균점수를 기준으로 내림차순 정렬해주시고, 평균점수가 같다면 즐겨찾기수를 기준으로 내림차순 정렬해주세요.

WITH MEAN_REST_REVIEW AS (
    SELECT   REST_ID, ROUND(AVG(REVIEW_SCORE),2) AS AVG_REVIEW_SCORE
    FROM     REST_REVIEW
    GROUP BY REST_ID
)

SELECT  A.REST_ID, 
        A.REST_NAME, 
        A.FOOD_TYPE,
        A.FAVORITES,
        A.ADDRESS,
        IFNULL(B.AVG_REVIEW_SCORE,0) AS SCORE
FROM    MEAN_REST_REVIEW AS B LEFT JOIN REST_INFO AS A 
    USING (REST_ID)
WHERE   A.ADDRESS LIKE '서울%'
ORDER BY B.AVG_REVIEW_SCORE DESC, A.FAVORITES DESC;