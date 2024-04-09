N, M = map(int, input().split(' '))
game_map = [[0] * M for _ in range(N)]

dr = [0, 1, 0, -1] # 우 하 좌 상
dc = [1, 0, -1, 0] 

def is_in_map(r:int , c:int)->bool:

    global N, M
    if( r < 0 or c < 0):
        return False
    
    if( r >= N or c >= M):
        return False 
    
    return True

dir_idx = 0
patient = 0 
cur_r, cur_c = 0, 0
cell_cnt = N * M
result = 0

while cell_cnt > 0:
    game_map[cur_r][cur_c] = 1
    cell_cnt -= 1
    next_r, next_c = cur_r + dr[dir_idx], cur_c + dc[dir_idx]
    
    if((cell_cnt > 0 ) and
       ((False == is_in_map(next_r, next_c)) or
       (0 != game_map[next_r][next_c]))):
        cell_cnt += 1
        dir_idx = (dir_idx + 1) % 4
        result += 1
        continue

    cur_r, cur_c = next_r, next_c

print(result)