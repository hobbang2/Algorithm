import sys 
input = sys.stdin.readline

N = int(input().strip())
target_str = list(input().strip())

dp = [float('inf') for _ in range(N)]
dp[0] = 0

prev_alpha_dict = {
    'B': 'J',
    'O': 'B',
    'J': 'O'
}

for idx in range(1, N):
    prev_alpha = prev_alpha_dict[target_str[idx]]
    for inner_idx in range(idx - 1, -1, -1):
        if(dp[inner_idx] == float('inf')):
            continue
        if(prev_alpha == target_str[inner_idx]):
            dp[idx] = min(dp[idx], dp[inner_idx] +  (idx - inner_idx) ** 2)

result = dp[N - 1]
result = -1 if result == float('inf') else result
print(result)
    