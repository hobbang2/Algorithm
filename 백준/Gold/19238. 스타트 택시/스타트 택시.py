"""
스타트 택시
- 손님을 태우면 이동거리 * 2 만큼 연료 충전
- 연료가 바닥나면 업무 끝 
- 손님을 내려줌과 동시에 연료가 바닥 나면 충전이 우선임 
- 최단 경로로 이동, 최단거리가 가장 짧은 승객 중 열, 행 번호가 작은 순서대로 태움 
"""
from collections import deque 
from copy import deepcopy

INF = 1000000
MAX_SIZE = 20 + 1
dr = [-1, 1, 0, 0] #상하좌우
dc = [0, 0, -1, 1]

def is_in_map(cur_r:int, cur_c:int, N:int)->bool:

    if(cur_r <= 0 or cur_c <= 0 ):
        return False 
    if(cur_r > N or cur_c > N):
        return False 
    return True

WALL = 1 

def bfs(start_r:int, start_c:int, end_r:int, end_c:int, N:int, cur_map:list, customer_info:list, find_dest:bool):

    visited = [ [False for c in range(N + 1)] for r in range(N + 1)]
    user_q = deque([[start_r,start_c, 0]])
    advocate_list = []
    minimum_size = INF

    while(user_q):

        cur_r, cur_c, cur_d = user_q.popleft()
        
        if( (False == find_dest) and (cur_d > minimum_size)):
            # 승객까지의 최단 거리를 모두 찾음 -> 종료
            return minimum_size, advocate_list
        # 후보자 리스트 업데이트 
        if( (False == find_dest) and (WALL < cur_map[cur_r][cur_c])):
            minimum_size = cur_d
            advocate_list.append(cur_map[cur_r][cur_c] - 2)
            continue
        
        if( (True == find_dest) and ((end_r == cur_r) and (end_c == cur_c))):
            return cur_d, []

        for ddr, ddc in zip(dr,dc):
            
            next_r = cur_r + ddr 
            next_c = cur_c + ddc 
            
            if(False == is_in_map(next_r, next_c, N)):
                continue
            if( WALL == cur_map[next_r][next_c]):
                continue
            if(True == visited[next_r][next_c]):
                continue
            
            visited[next_r][next_c] = True
            user_q.append((next_r, next_c, cur_d + 1))
    
    
    # 승객 태우러 못 가는 경우로 판단
    return minimum_size, advocate_list

def find_target_customer( ad_list:list, customer_info:list):
    
    priority = 10000
    target = -1 
    
    for cust_idx in ad_list:
        
        s, _ = customer_info[cust_idx]
        
        if( s < priority):
            priority = s
            target = cust_idx
    
    return target

def main():
    
    # 연료는 무한히 많이 담을 수 있음
    N, M, oil = list(map(int,input().split(' ')))
    cur_map = [[0 ]* ( N + 1)] + [ [0] + list(map(int, input().split(' '))) for r in range(N)]
    taxi_r, taxi_c = list(map(int, input().split(' '))) # 1부터 시작 
    tmp_customer_info = [ list(map(int,input().split(' '))) for m in range(M)]
    customer_info = []

    for idx, (s_r, s_c, e_r, e_c) in enumerate(tmp_customer_info):
        
        cur_map[s_r][s_c] = ( idx + 2 )
        customer_info.append([s_r * 100 + s_c, e_r * 100 + e_c])


    for turn in range(M):


        # 1. 각 승객까지의 최단거리 구하기
        spend_oil_start , ad_l = bfs(taxi_r, taxi_c, -1, -1 , N, cur_map, customer_info, False)
        target = find_target_customer(ad_l,customer_info)
        
        s, e = customer_info[target]
        s_r , s_c = s // 100 , s % 100 
        e_r , e_c = e // 100 , e % 100
        
        cur_map[s_r][s_c] = 0 
        
        if( oil < spend_oil_start):
            oil = -1 
            break
        
        spend_oil_dest, _ = bfs(s_r, s_c, e_r, e_c, N, cur_map, customer_info, True)
        
        if(INF == spend_oil_dest):
            oil = -1 
            break
        
        if(oil - spend_oil_start - spend_oil_dest  >= 0):
            oil -= (spend_oil_start + spend_oil_dest)
            oil += (spend_oil_dest * 2)
            taxi_r = e_r
            taxi_c = e_c
        else:
            # 실패
            oil = -1
            break
        # 2. 승객 정렬 0, 1, 2 원소까지만 이용해서 작은 순으로 정렬 
        # 3. 가장 첫 번째 손님 pop
        # 4. 현재 원료 - 이동거리 >= 0 이면 이동하고 연료 충전
        # 5. 다시 1부터 계산

    print(oil)

main()