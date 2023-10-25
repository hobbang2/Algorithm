import sys 
input = sys.stdin.readline

MOD = 1000000009

T = int(input())
target = [int(input()) for tc in range(T)]
MAX_N = max(target)
dp = [0 for _ in range(MAX_N + 1)]
dp[1] = 1 ; dp[2] = 2; dp[3] = 4; dp[4] = 7

last = 4

for item in target:

    if(0 == dp[item]):
        for n in range(last + 1, item + 1):
            dp[n] = ( dp[n-1] + dp[n-2] + dp[n-3] ) % MOD
        last = item

    print(dp[item])


