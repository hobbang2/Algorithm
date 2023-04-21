import sys 
input = sys.stdin.readline

T = int(input())

for tc in range(T):
    
    N = int(input())
    dp = [[0] * 100002 for _ in range(2)]
    stickers = [ list(map(int,input().split(' '))) for _ in range(2)]
    dp[0][1] = stickers[0][0]
    dp[1][1] = stickers[1][0]
    
    for idx in range(2, N + 1):
        dp[0][idx] = max(dp[1][idx-1], dp[1][idx-2]) + stickers[0][idx-1]
        dp[1][idx] = max(dp[0][idx-1], dp[0][idx-2]) + stickers[1][idx-1]

    print(max(dp[0][N], dp[1][N]))
    