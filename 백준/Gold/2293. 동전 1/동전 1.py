n, k = map(int,input().split(' '))
coin_value = []

for n_idx in range(n):
    coin_value.append(int(input()))

coin_value.sort()
dp = [ 0 for _ in range(k + 1)]
dp[0] = 1

for coin in coin_value:
    for value in range(coin, k + 1):
        dp[value] += dp[value - coin]

print(dp[k])