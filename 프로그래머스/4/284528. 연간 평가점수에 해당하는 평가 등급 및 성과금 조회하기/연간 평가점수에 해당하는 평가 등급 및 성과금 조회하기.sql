-- 코드를 작성해주세요
-- 사번, 성명, 평가등급, 성과금 조회

WITH HR_GRADE_YEAR_MEAN AS (
    SELECT  EMP_NO,
            AVG(SCORE) AS AVG_SCORE
    FROM    HR_GRADE
    WHERE   YEAR = 2022
    GROUP BY EMP_NO
),


HR_GRADE_PERCENT_TBL AS(
    SELECT  EMP_NO,
            CASE
                WHEN AVG_SCORE >= 96 THEN 'S'
                WHEN AVG_SCORE >= 90 THEN 'A'
                WHEN AVG_SCORE >= 80 THEN 'B'
                ELSE 'C'
            END AS GRADE,
            CASE
                WHEN AVG_SCORE >= 96 THEN 0.2
                WHEN AVG_SCORE >= 90 THEN 0.15
                WHEN AVG_SCORE >= 80 THEN 0.1
                ELSE 0
            END AS PERCENT
    FROM    HR_GRADE_YEAR_MEAN
)

SELECT  A.EMP_NO,
        A.EMP_NAME,
        B.GRADE,
        A.SAL * B.PERCENT AS BONUS
FROM    HR_EMPLOYEES AS A, HR_GRADE_PERCENT_TBL AS B
WHERE   A.EMP_NO = B.EMP_NO
ORDER BY A.EMP_NO ASC