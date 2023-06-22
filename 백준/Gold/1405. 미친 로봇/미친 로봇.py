MAX_MAP_SIZE = 14 * 2 + 1

robots = list(map(int, input().split(' ')))
act_num = robots[0]
act_proba = robots[1:]

robot_move_map = [ [False] * MAX_MAP_SIZE for _ in range(MAX_MAP_SIZE)] 
result = 0.0

def dfs(cnt:int, r:int, c:int, prob:float):
    
    global robot_move_map, act_num, result 

    if(True == robot_move_map[r][c]):
        return
    
    elif(act_num == cnt):
        result += prob 

    else:
        robot_move_map[r][c] = True
        dfs(cnt + 1, r    , c + 1, prob * act_proba[0] / 100) # 동
        dfs(cnt + 1, r    , c - 1, prob * act_proba[1] / 100) # 서 
        dfs(cnt + 1, r + 1, c    , prob * act_proba[2] / 100) # 남 
        dfs(cnt + 1, r - 1, c    , prob * act_proba[3] / 100) # 북
        robot_move_map[r][c] = False
    
    return 

dfs(0, 14, 14, 1)
print(result)