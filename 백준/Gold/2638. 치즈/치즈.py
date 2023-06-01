import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int,input().rstrip().split(' '))
grid = [ list(map(int,input().rstrip().split(' '))) for _ in range(N)]
cheeze_cnt = sum([ sum(_) for _ in grid])

# 북동남서
dx = [-1,0,1,0]
dy = [0,1,0,-1]

def get_air_cnt(cur_grid:list, x:int, y:int, orient_ground_num:int):

    cnt = 0 

    for dir_x, dir_y in zip(dx,dy):
        next_x = x + dir_x
        next_y = y + dir_y

        if( False == is_in_map(next_x,next_y)):
            continue
        
        cnt += int (orient_ground_num == cur_grid[next_x][next_y])

    return cnt

def is_in_map(x:int, y:int):
    
    global N,M
    
    if( x < 0 or y < 0):
        return False 

    if( x >= N or y >= M):
        return False

    return True
 
# 땅 번호 매기기 
def bfs(ground_num:int):

    global N,M 
    global grid

    q = deque([])
    q.append([0,0,0])

    while len(q) > 0 :
        
        cur_x, cur_y, cur_depth = q.pop()
        
        for dir_x, dir_y in zip(dx,dy):
            next_x = cur_x + dir_x
            next_y = cur_y + dir_y

            if( False == is_in_map(next_x,next_y)):
                continue
            

            if( 0 != grid[next_x][next_y]) :
                continue
            
            grid[next_x][next_y] = ground_num
            q.append([next_x,next_y,cur_depth+1])

# 매겨진 땅 번호는 3부터 시작
# 3보다 큰 경우 치즈 내부에 있는 땅
start_grid_num = 3
year = 0

while(cheeze_cnt > 0):
    
    year += 1
    grid_num = start_grid_num

    for x in range(N):
        for y in range(M):
            
            # 아직 번호가 매겨지지 않았다면 번호 부여
            if(grid[x][y] == 0):
                bfs(grid_num)
                grid_num += 1

    # 같은 연도에 녹아 없어진 치즈를 air cnt에 포함시키지 않기 위해 선언
    next_grid = [[0]* M for _ in range(N)]

    for x in range(N):
        for y in range(M):

            # 치즈면 인접한 주변 공기 수를 센다.
            if(grid[x][y] == 1):

                air_cnt = get_air_cnt(grid, x,y, 3)
                # 살아남은 치즈
                next_grid[x][y] = int(air_cnt < 2)
                # 녹은 치즈만큼 빼기
                cheeze_cnt -= int(air_cnt >= 2)

    grid = next_grid

print(year)