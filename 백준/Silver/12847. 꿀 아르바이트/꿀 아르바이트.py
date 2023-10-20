import sys
input = sys.stdin.readline

N, M = list(map(int,input().strip().split(' ')))
pay_per_day = list(map(int,input().strip().split(' ')))

start_day = 0 
cur_pay = sum(pay_per_day[:M])
result = cur_pay

for idx in range(M, N):
    cur_pay -= pay_per_day[start_day]
    cur_pay += pay_per_day[idx]
    start_day += 1
    result = max(result, cur_pay)

print(result)


