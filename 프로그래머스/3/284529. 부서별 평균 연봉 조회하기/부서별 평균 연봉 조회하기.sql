-- 코드를 작성해주세요
-- HR_DEPARTMENT와 HR_EMPLOYEES
-- 부서별 평균 연봉 조회
-- 소수점 첫째자리에서 반올림, AVG_SAL, 평균 연봉을 기준으로 내림차순 정렬

SELECT      A.DEPT_ID,
            MAX(B.DEPT_NAME_EN) AS DEPT_NAME_EN,
            ROUND(AVG(SAL),0) AS AVG_SAL
FROM        HR_EMPLOYEES AS A, HR_DEPARTMENT AS B
WHERE       A.DEPT_ID = B.DEPT_ID
GROUP BY    A.DEPT_ID
ORDER BY    AVG(SAL) DESC;