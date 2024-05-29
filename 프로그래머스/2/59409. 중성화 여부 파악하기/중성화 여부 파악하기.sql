-- 코드를 입력하세요
SELECT  ANIMAL_ID,
        NAME,

        CASE
            WHEN SUBSTRING_INDEX(SEX_UPON_INTAKE, ' ', 1) IN ('Neutered', 'Spayed') THEN 'O'
            ELSE 'X'
        END AS 중성화
FROM    ANIMAL_INS

