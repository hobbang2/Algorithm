N = int(input())

dp = [1] + [0] * 30
dp[2] = 3
dp[4] = 11 # 2 + 3 * 3

for cur_size in range(4, N + 1, 2):
    dp[cur_size] = 3 * dp[cur_size - 2]

    for j in range(4, N + 1, 2):
        dp[cur_size] += 2 * dp[cur_size - j] 

print(dp[N])