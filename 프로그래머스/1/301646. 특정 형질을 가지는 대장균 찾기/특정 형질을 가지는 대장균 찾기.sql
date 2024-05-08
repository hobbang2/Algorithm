-- 코드를 작성해주세요
SELECT  COUNT(ID) AS COUNT
FROM    ECOLI_DATA
WHERE   (0 = ( GENOTYPE & 2))
    AND ((0 < ( GENOTYPE & 1))
    OR (0 < ( GENOTYPE & 4)))