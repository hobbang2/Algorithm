import sys

input = sys.stdin.readline

n, k = map(int, input().split(' '))
coins = list(set([int(input()) for _ in range(n)]))

# money_dp[i]: 최소 동전 개수로 i원을 만들 때의 동전 개수
money_dp = [10001] * (k + 1)
money_dp[0] = 0  # 기본 경우: 0원을 만드는데 필요한 동전 개수는 0

for coin in coins:
    for target_value in range(coin, k + 1):
        money_dp[target_value] = min(money_dp[target_value], money_dp[target_value - coin] + 1)

result = -1 if 10001 == money_dp[k] else money_dp[k]
print(result)