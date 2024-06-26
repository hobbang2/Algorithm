SELECT YEAR(O.SALES_DATE) YEAR,
 DATE_FORMAT(O.SALES_DATE, "%m") MONTH,
 U.GENDER,
 COUNT(DISTINCT U.USER_ID) USERS
from USER_INFO U inner join ONLINE_SALE O on U.USER_ID=O.USER_ID
where U.gender IS NOT NULL
group by 1, 2, 3
ORDER BY 1 ASC, 2 ASC, 3 ASC