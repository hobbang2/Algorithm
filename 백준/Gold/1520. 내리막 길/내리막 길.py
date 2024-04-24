import sys
from collections import deque

input = sys.stdin.readline

dr, dc =  [ -1, 1, 0, 0], [0, 0, -1, 1]

M, N = map(int, input().split(' '))
user_map = [list(map(int, input().split(' ')))for _ in range(M)]
info_map = [[0] * N for _ in range(M)]
visited = [[0] * N for _ in range(M)]
dp = [[-1] * N for _ in range(M)]
result = -1

def dfs(r:int , c:int)->int:
    global result
    
    if( (r == M - 1) and (c == N - 1)):
        return 1
    
    if(dp[r][c] >= 0):
        return dp[r][c]
    
    available_check = False
    cnt = 0 
    for ddr, ddc in zip(dr, dc):
        next_r, next_c = r + ddr, c + ddc
        if(0 > next_r or M <= next_r):
            continue
        if(0 > next_c or N <= next_c):
            continue
        if(visited[next_r][next_c] != 0):
            continue
        if(user_map[next_r][next_c] >= user_map[r][c]):
            continue
        
        visited[next_r][next_c] = 1
        cnt += dfs(next_r, next_c)
        visited[next_r][next_c] = 0
    dp[r][c] = cnt        

    return dp[r][c]
    

dfs(0, 0)
print(dp[0][0])