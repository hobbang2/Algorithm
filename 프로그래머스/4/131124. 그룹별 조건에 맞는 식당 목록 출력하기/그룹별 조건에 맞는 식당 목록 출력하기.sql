-- 코드를 입력하세요
-- 리뷰를 가장 많이 작성한 회원의 리뷰들을 조회하는 SQL문을 작성해주세요. 회원 이름, 리뷰 텍스트, 리뷰 작성일이 출력되도록 작성해주시고, 결과는 리뷰 작성일을 기준으로 오름차순, 리뷰 작성일이 같다면 리뷰 텍스트를 기준으로 오름차순 정렬

SELECT  M.MEMBER_NAME,
        R.REVIEW_TEXT, 
        DATE_FORMAT(R.REVIEW_DATE,'%Y-%m-%d') AS REVIEW_DATE
FROM    REST_REVIEW AS R LEFT JOIN MEMBER_PROFILE AS M
    USING (MEMBER_ID)
WHERE   R.MEMBER_ID = (SELECT   MEMBER_ID
                       FROM     REST_REVIEW
                       GROUP BY MEMBER_ID
                       ORDER BY COUNT(MEMBER_ID) DESC
                       LIMIT 1)
ORDER BY R.REVIEW_DATE ASC, R.REVIEW_TEXT ASC