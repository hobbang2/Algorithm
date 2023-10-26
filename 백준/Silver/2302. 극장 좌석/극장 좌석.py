N = int(input())
static_seat_num = int(input())
dp = [1] * (N+10)
dp[1] = 1 ; dp[2] = 2; dp[3] = 3; dp[4] = 5;

for n in range(5,N + 1):
    dp[n] = dp[n - 1] + dp[n - 2]

last = 0 
result = 1

for static_seat in range(static_seat_num):
    cur_seat_num = int(input())
    idx = cur_seat_num - last - 1
    result *= dp[idx]
    last = cur_seat_num

result *= dp[N - last]
print(result)