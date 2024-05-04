-- 코드를 입력하세요
-- 2022년 4월 13일 취소되지 않은 
-- 흉부외과(CS) 진료 예약 내역을 조회하는 SQL문

-- 진료예약번호, 환자이름, 환자번호, 진료과코드, 의사이름, 진료예약일시 항목이 출력
SELECT  A.APNT_NO,
        B.PT_NAME,
        B.PT_NO, 
        C.MCDP_CD, 
        C.DR_NAME, 
        A.APNT_YMD
FROM    APPOINTMENT AS A LEFT JOIN PATIENT AS B ON A.PT_NO = B.PT_NO
        LEFT JOIN DOCTOR AS C ON A.MDDR_ID = C.DR_ID
WHERE   A.APNT_CNCL_YN = 'N' 
AND     DATE_FORMAT(APNT_YMD ,'%Y-%m-%d') = '2022-04-13'
AND     C.MCDP_CD = 'CS'
ORDER BY APNT_YMD ASC;

