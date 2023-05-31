import copy

N,M,K = map(int, input().split())
cube = [list(map(int,input().split(' '))) for _ in range(N)]
rotate = [list(map(int,input().split(' '))) for _ in range(K)]
result = 50000

def right_roate(target_cube:list, idx_arr:list)->list:
    
    start_r, start_c, cnt_idx = idx_arr

    N = start_r + cnt_idx
    M = start_c + cnt_idx

    origin_left_top = target_cube[start_r][start_c]
    next_left_top = target_cube[start_r + 1][start_c]
    # left_top, right_top = target_cube[start_r + 1][start_c], target_cube[start_r][M-2]
    # left_bottom, right_bottom = target_cube[N-1][start_c + 1], target_cube[N-2][M-1]


    # 왼쪽 옆
    for idx in range(start_r, N-1):
        target_cube[idx][start_c] = target_cube[idx+1][start_c]

    # 아랫면 
    for idx in range(start_c, M-1):
        target_cube[N-1][idx] = target_cube[N-1][idx+1]

    # 오른쪽 옆
    for idx in range(N-1, start_r - 1, -1):
        target_cube[idx][M-1] = target_cube[idx-1][M-1] 

    # 윗면 
    for idx in range(M-1, start_c - 1, -1):
        target_cube[start_r][idx] = target_cube[start_r][idx-1] 



    # 가장자리 업데이트 
    target_cube[start_r][start_c] = next_left_top
    target_cube[start_r][start_c+1] = origin_left_top

    return target_cube

def run_rotate(cnt :int, rotate_order:list):
    
    global result
    global N
    global k
    global rotate
    global cube

    if(cnt == K):
        target_cube = copy.deepcopy(cube)
        for order in rotate_order:
            r,c,s = rotate[order]
            r -= 1
            c -= 1
            # target_cube = cube[r-s:r+s+1,c-s:c+s+1]

            for s_idx in range(1, s + 1):
                # cube 값이 변경되길 기대
                right_roate(target_cube,[r-s_idx, c-s_idx, 2 * s_idx + 1])
        
        for n in range(N):
            cur_sum = sum(target_cube[n])
            result = min(cur_sum,result )

        del(target_cube)

        return 
    
    for idx in range(K):
        
        if idx in rotate_order:
            continue 

        rotate_order.append(idx)
        run_rotate(cnt+1,rotate_order)
        rotate_order.pop()
    
    return

run_rotate(0, [])
print(result)

