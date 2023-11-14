import sys 
input = sys.stdin.readline

T = int(input())

for tc in range(T):
    
    coin_num = int(input())
    coin_values = list(map(int,input().split(' ')))
    target_value = int(input())
    dp = [0 for _ in range(target_value + 1)]
    dp[0] = 1

    for coin in coin_values:
        for next_value in range(coin, target_value + 1):
            dp[next_value] += (dp[next_value - coin])

    print(dp[target_value])
