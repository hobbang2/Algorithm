from math import sqrt

N = int(input())
root_n = int(sqrt(N))
dp = [0 for _ in range(N+1)]
dp[0] = 0
dp[1] = 1

for n in range(1, N + 1):

    root_value = int(sqrt(n))
    check_list = []

    for check_n in range(root_value, 0 , -1):
        rest = n - (check_n ** 2)
        if( rest == n):
            continue
        if(rest == 0):
            check_list.append(1)
            break
        else:
            check_list.append(dp[check_n ** 2] + dp[rest])

    dp[n] = min(check_list)

print(dp[N])