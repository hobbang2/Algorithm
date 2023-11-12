import sys
input = sys.stdin.readline

result_cnt = 0

while True:
    N = int(input())
    if 0 == N:
        break
    dp=[]
    for i in range(N):
        dp.append(list(map(int,input().split())))
    result_cnt += 1
    result = 0

    dp[1][0] += dp[0][1]
    dp[1][1] += min(dp[0][1], dp[0][1] + dp[0][2], dp[1][0])
    dp[1][2] += min(dp[0][1], dp[0][1] + dp[0][2], dp[1][1])

    for i in range(2,N):
        dp[i][0] += min(dp[i-1][0], dp[i-1][1])
        dp[i][1] += min(dp[i-1][0], dp[i-1][1], dp[i-1][2], dp[i][0])
        dp[i][2] += min(dp[i-1][1], dp[i-1][2], dp[i][1])

    print(f"{result_cnt}. {dp[N-1][1]}")
