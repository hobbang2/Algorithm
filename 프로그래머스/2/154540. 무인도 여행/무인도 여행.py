from copy import deepcopy
from collections import deque

dr = [-1, 1, 0, 0] # 상하좌우
dc = [0, 0, -1, 1]

def is_in_map(target_coord:list, max_coord:tuple):
    
    r,c = target_coord
    MAX_R, MAX_C = max_coord
    
    if( (0 <= r < MAX_R) and 
        (0 <= c < MAX_C)):
        return True
    return False

def bfs(start_coord:list, maps:list, max_coord:tuple):
    
    q = deque([start_coord])
    cur_stay_days = 0
    
    while len(q) > 0:
        r, c = q.pop()
        for ddr, ddc in zip(dr, dc):
            next_r, next_c = r + ddr, c + ddc
            if(False == is_in_map([next_r, next_c], max_coord)):
                continue
            if('X' == maps[next_r][next_c]):
                continue
            cur_stay_days += int(maps[next_r][next_c])
            maps[next_r][next_c] = 'X'
            q.append([next_r, next_c])
    return cur_stay_days

def solution(maps):
    visited = [list(origin_r) for origin_r in maps]
    MAX_R, MAX_C = len(maps), len(maps[0])
    answer = []
    
    for r in range(MAX_R):
        for c in range(MAX_C):
            if( 'X'== visited[r][c]):
                continue
            stay_days = int(maps[r][c])
            visited[r][c] = 'X'
            stay_days += bfs([r,c], visited, (MAX_R, MAX_C))
            
            if(stay_days <= 0):
                continue
            
            answer.append(stay_days)
            
    if(len(answer) == 0):
        answer.append(-1)
    
    return sorted(answer)