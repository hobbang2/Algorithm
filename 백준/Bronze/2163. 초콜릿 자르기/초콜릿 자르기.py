# 1x1 초콜릿으로 쪼개기 위한 최소횟수
N, M = map(int, input().split(' '))
result = (N - 1) + N * (M - 1)
print(result)
