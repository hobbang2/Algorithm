"""
x, y : 행 열 
- 각 물고기는 번호와 방향을 가짐 (1~16, 두 물고기가 같은 방향을 가지지 않음, 방향은 8방)
- 청소년 상어가 위치한 물고기를 먹는다 (상어의 방향은 물고기의 방향과 같음)
- 물고기 이동
- 번호가 작은 물고기부터 이동, 한 칸 이동 : 빈칸 또는 다른 물고기가 있는 칸 (상어가 있거나 경계는 이동x)
- 각 물고기는 방향이 이동할 수 있는 칸을 향할 때 까지 45도 반시계 회전 (이동할 수 있는 칸이 없으면 이동x)
- 물고기가 다른 물고기가 있는 칸으로 이동할 때는 서로의 위치를 바꿈 
- 물고기의 이동이 모두 끝나면 상어가 이동 (방향에 있는 칸으로 이동, 한 번에 여러칸 이동)
  - 이동한 칸에 물고기가 있으면 물고기 먹고 물고기의 방향을 가짐
  - 이동 중 지나가는 칸에 있는 물고기는 먹지 않음, 물고기가 없는 칸으로는 이동x
  - 상어가 이동할 수 있는 칸이 없으면 공간을 벗어나 집으로 감 
"""
from copy import deepcopy

MAP_SIZE  = 4 
SHARK_NUM = 22
FISH_MAX  = 16
DIR_MAX   = 8 

FISH_IDX, FISH_X, FISH_Y, FISH_DIR, FISH_LIFE = (0,1,2,3,4)


fish_info = [[-1,-1,-1,-1,False]] # 물고기 번호 별 정렬 (번호, 방향: 바뀔수 있음)
fish_map = [[0 for _ in range(MAP_SIZE)] for __ in range(MAP_SIZE)]
dx = [-1,-1, 0, 1, 1, 1, 0, -1] # 북, 서북, 서, 서남, 남, 동남, 동, 동북
dy = [0, -1, -1, -1, 0, 1, 1, 1]
result = 0 

def is_in_map(cur_x:int, cur_y:int)->bool:

    if((cur_x < 0) or (cur_y < 0)):
        return False
    if((cur_x >= MAP_SIZE) or (cur_y >= MAP_SIZE)):
        return False
    return True

def move_fish():
    pass

def dfs(shark_x:int, shark_y:int, shark_d:int, 
        fish_arr:list, cur_fish_map:list, cur_score:int)->None:
    global result
    
    if( False == is_in_map(shark_x, shark_y)):
        result = max(cur_score, result)
        return
    
    for idx in range( 1 ,FISH_MAX + 1):
        fish_idx, cur_fish_x, cur_fish_y, origin_dir, cur_life = fish_arr[idx]
        
        if(False == cur_life):
            continue

        for d_idx in range(0, DIR_MAX):
            next_dir = (origin_dir + d_idx) % DIR_MAX
            next_fish_x = cur_fish_x + dx[next_dir] 
            next_fish_y = cur_fish_y + dy[next_dir]

            if( (False == is_in_map(next_fish_x,next_fish_y)) or
               (SHARK_NUM == cur_fish_map[next_fish_x][next_fish_y])):
                continue

            # 물고기 이동
            next_fish_idx = cur_fish_map[next_fish_x][next_fish_y]
            if( 0 == next_fish_idx):
                cur_fish_map[cur_fish_x][cur_fish_y] = 0 
                fish_arr[fish_idx][FISH_X] = next_fish_x
                fish_arr[fish_idx][FISH_Y] = next_fish_y
                fish_arr[fish_idx][FISH_DIR] = next_dir 
                cur_fish_map[next_fish_x][next_fish_y] = fish_idx 
            # 이미 물고기가 있는 경우 
            else:
                cur_fish_map[cur_fish_x][cur_fish_y] = next_fish_idx
                fish_arr[next_fish_idx][FISH_X] = cur_fish_x
                fish_arr[next_fish_idx][FISH_Y] = cur_fish_y
                
                fish_arr[fish_idx][FISH_X] = next_fish_x
                fish_arr[fish_idx][FISH_Y] = next_fish_y
                fish_arr[fish_idx][FISH_DIR] = next_dir 
                cur_fish_map[next_fish_x][next_fish_y] = fish_idx 
            
            break #  한 번만 이동

    
    for idx in range(1,4):
        next_x = shark_x + ( dx[shark_d] * idx)
        next_y = shark_y + ( dy[shark_d] * idx)

        if(False == is_in_map(next_x, next_y)):
            result = max(cur_score, result)
            break
        
        cur_fish_idx = cur_fish_map[next_x][next_y]

        # 상어가 먹을 물고기가 없음 
        if( 0 == cur_fish_idx ):
            continue

        cur_fish_map[shark_x][shark_y] = 0 
        cur_fish_map[next_x][next_y]   = SHARK_NUM
        fish_arr[cur_fish_idx][FISH_LIFE] = False

        result = max(result,  cur_score + cur_fish_idx)
        dfs(next_x, next_y, fish_arr[cur_fish_idx][FISH_DIR],
            deepcopy(fish_arr), deepcopy(cur_fish_map), cur_score + cur_fish_idx)
        
        cur_fish_map[shark_x][shark_y] = SHARK_NUM 
        cur_fish_map[next_x][next_y]   = cur_fish_idx
        fish_arr[cur_fish_idx][FISH_LIFE] = True

def main():
    
    for x in range(MAP_SIZE):
        tmp_info = list(map(int,input().split(' ')))

        for y in range(0, MAP_SIZE):

            fish_map[x][y] = tmp_info[y * 2]
            fish_info.append([tmp_info[y * 2], x,y,tmp_info[y * 2 + 1] - 1, True])
            
    fish_info.sort() # index 기준 정렬

    score = fish_map[0][0]
    fish_info[score][FISH_LIFE] = False
    fish_map[0][0] = SHARK_NUM

    dfs(0,0, fish_info[score][FISH_DIR], deepcopy(fish_info), deepcopy(fish_map),score )
    
if __name__ == "__main__":
    main()
    print(result)