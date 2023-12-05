import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**9)

N = int(input())
adj_graph = [[] for _ in range(N + 1)]
dp = [[0] * 2 for _ in range(N + 1)]
visit = [0 for _ in range(N + 1)]
for _ in range(N - 1):
    u, v = map(int, input().split())
    adj_graph[u].append(v)
    adj_graph[v].append(u)

def dfs(v):
    visit[v] = 1
    dp[v][0] = 0
    dp[v][1] = 1
    for i in adj_graph[v]:
        if visit[i] == 0:
            dfs(i)
            dp[v][0] += dp[i][1]
            dp[v][1] += min(dp[i][0], dp[i][1])

dfs(1)
print(min(dp[1][0], dp[1][1]))
