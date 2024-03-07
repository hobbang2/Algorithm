"""
모든 전구를 그기 위해 눌려야하는 스위치의 수 
""" 

from copy import deepcopy

LIGHT_ON = 'O'
LIGHT_DOWN = '#'
N = 10
light_map = [list(input()) for _ in range(N)]

result = 101
dr, dc = [-1, 1, 0, 0], [0, 0, -1, 1] # 상하좌우

def is_in_map(r:int, c:int)->bool:

    if(r < 0 or c < 0):
        return False
     
    if(r >= N or c >= N):
        return False 
    
    return True 

def turn_switch_around(r:int, c:int, cpy_map:list)->None:

    for ddr, ddc in zip(dr, dc):
        next_r, next_c = r + ddr, c + ddc
        
        if(False == is_in_map(next_r, next_c)):
            continue 
        
        cpy_map[next_r][next_c] = LIGHT_DOWN if (cpy_map[next_r][next_c] == LIGHT_ON) else LIGHT_ON

def is_all_turn_off(cpy_map)->bool:
    
    for r in range(10):
        for c in range(10):
            if(LIGHT_ON == cpy_map[r][c]):
                return False 
            
    return True 

for num in range(0, 1024):

    cur_result = 0
    bit_mask_light = list(map(int,list(format(num, '010b'))))
    cpy_map = deepcopy(light_map)

    for idx, item in enumerate(bit_mask_light):
        if(1 == item):
            cur_result += 1
            cpy_map[0][idx] = LIGHT_DOWN if (cpy_map[0][idx] == LIGHT_ON) else LIGHT_ON
            turn_switch_around(0, idx, cpy_map)

    for line in range(1, N):
        for col in range(10):
            if(LIGHT_ON == cpy_map[line - 1][col]):
                # turn on swith
                cur_result += 1
                cpy_map[line][col] = LIGHT_DOWN if (cpy_map[line][col] == LIGHT_ON) else LIGHT_ON
                turn_switch_around(line, col, cpy_map)

    is_success = is_all_turn_off(cpy_map)
    
    if(is_success):
        result = min(result, cur_result)

result = -1 if 101 == result else result 

print(result)