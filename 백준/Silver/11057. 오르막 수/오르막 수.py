MY_MOD = 10007
N = int(input())

dp = [1 for _ in range(10)]

for i in range(1, N):
    for j in range (1,10):
        dp[j] += ( dp[j-1] % MY_MOD)

print(sum(dp) % MY_MOD)