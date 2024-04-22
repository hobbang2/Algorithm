import sys 
input = sys.stdin.readline
# 6
# 10 20 10 30 20 50
N = int(input())
sequence = list(map(int, input().strip().split(' ')))
dp = [1] * N
result_num = 1
result_sequence = []

for i in range(1, N):
    for j in range(0, i):
        if((sequence[i] > sequence[j]) and \
            (dp[i] < dp[j] + 1)):
            dp[i] = dp[j] + 1
    result_num = max(result_num, dp[i])

cnt = result_num

for idx in range(N - 1, -1, -1):
    if(dp[idx] == cnt):
        result_sequence.append(sequence[idx])
        cnt -= 1    

print(result_num)
print(*result_sequence[::-1])