-- 코드를 입력하세요
-- 식품분류별로 가격이 제일 비싼 식품의 분류, 가격, 이름
SELECT  CATEGORY,  
        PRICE AS MAX_PRICE,
        PRODUCT_NAME
FROM    (
    SELECT   CATEGORY,  
             PRICE,
             PRODUCT_NAME,
             DENSE_RANK() OVER (PARTITION BY CATEGORY ORDER BY PRICE DESC) AS 'PRICE_RANK'
    FROM     FOOD_PRODUCT
    WHERE    CATEGORY IN ('과자', '국', '김치', '식용유')
) AS Z
WHERE    Z.PRICE_RANK = 1
ORDER BY MAX_PRICE DESC