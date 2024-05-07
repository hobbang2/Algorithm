-- 코드를 입력하세요
-- 상반기 아이스크림 총주문량이 3,000보다 높으면서 아이스크림의 주 성분이 과일인 아이스크림의 맛을 총주문량이 큰 순서대로 조회하는 SQL 문
SELECT  FLAVOR	
FROM    FIRST_HALF
WHERE   TOTAL_ORDER > 3000
    AND FLAVOR	 IN (SELECT FLAVOR	 FROM ICECREAM_INFO WHERE INGREDIENT_TYPE = 'fruit_based')
GROUP BY FLAVOR	
ORDER BY SUM(TOTAL_ORDER) DESC 
