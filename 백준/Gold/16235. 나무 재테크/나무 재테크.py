# 양분 조사, 처음에는 5만큼 들어있음 
# 한 칸에 여러 개의 나무가 있을 수 있음 
# 봄 : 나이 어린 나무 부터 양분을 먹는다.
#     땅에 양분이 부족하다면 죽는다.
# 여름 : 양분을 먹지 못한 나무는 죽어서 양분이 된다.
#        나이 // 2 만큼
# 가을 : 5의 배수인 나무 8방으로 번식 (나이1)
# 겨울 : 양분 추가 A[r][c]
# K 년 후 살아있는 나무의 수 
import sys 
import copy
from queue import PriorityQueue
from collections import deque

input = sys.stdin.readline
# 행열 
# 북, 북동, 동, 남동, 남, 남서, 서, 북서
dx = [-1, -1, 0, 1, 1,  1,  0, -1]
dy = [ 0,  1, 1, 1, 0, -1, -1, -1] 

# 땅 크기, 심은 나무, 흐를 시간
N, M, K = map(int,input().rstrip().split(' '))
energy = [list(map(int,input().rstrip().split(' '))) for _ in range(N)]
earth = [[5]*N for _ in range(N)]
tree_cnt = 0

# 입력되는 나무의 위치가 모두 다르므로 deque 이용 
# 애기나무는 제일 왼쪽으로 넣어주면 됨
tree_deque = [ [deque([]) for _ in range(N) ]  for _ in range(N) ]

for m in range(M):

    x,y,z = map(int,input().rstrip().split(' '))
    tree_deque[x-1][y-1].append(z)
    tree_cnt += 1

# 봄, 여름, 겨울 로직 통합
def spring_summer_winter(tree_deque:list, earth:list)->tuple:
    
    global N, energy
    dead_cnt = 0
    life_tree_list = deque([])

    for x in range(N):
        for y in range(N):
            
            # deque이 비었는지 확인
            if False == bool(tree_deque[x][y]) :
                earth[x][y] += energy[x][y]
                continue
            
            # 양분 먹은 나무를 저장 
            next_deque = deque([])
            # 죽은 나무의 영양분 
            dead_tree_energe = 0

            # 현재 deque에서 하나씩 빼면서 본다.
            while( True == bool(tree_deque[x][y]) ):
                
                # 제일 어린 나무부터 
                tree_age = tree_deque[x][y].popleft()
                cur_energy = earth[x][y]

                # 자신의 나이만큼 지구의 영양소 흡수해야하므로 
                # 나무의 나이보다 남은 영양소가 커야한다.
                if(tree_age <= cur_energy):
                    earth[x][y] -= tree_age
                    tree_age += 1
                    next_deque.append(tree_age)

                    # 5의 배수이면 가을에 번식한다
                    if( 0 == tree_age % 5):
                        life_tree_list.append([x,y,tree_age])
                # 땅에 남은 영양분이 나이보다 적으면 죽는다.
                else:
                    dead_tree_energe += ( tree_age // 2)
                    dead_cnt += 1

            # 살아남은 나무들
            tree_deque[x][y] = next_deque
            earth[x][y] += (dead_tree_energe)
            earth[x][y] += energy[x][y]

    
    return life_tree_list,dead_cnt

def is_in_map(x:int, y:int)->bool:
    
    global N

    if( x < 0 or y < 0):
        return False 
    
    if( x >= N or y >= N):
        return False 
    
    return True 

def autumn(life_tree_list:list,tree_deque:list)->int:
    
    life_cnt = 0

    # 번식한 나무는 1살부터 시작
    for life_x, life_y, _ in life_tree_list:
        for dir_x, dir_y in zip(dx,dy):
            next_x = life_x + dir_x
            next_y = life_y + dir_y 

            if(False == is_in_map(next_x, next_y)):
                continue
            
            tree_deque[next_x][next_y].appendleft(1)
            life_cnt += 1
    return life_cnt

for k in range(K):

    if(0 == tree_cnt):
        break 

    life_t, dead_cnt = spring_summer_winter(tree_deque, earth)
    tree_cnt -= dead_cnt
    tree_cnt += autumn(life_t,tree_deque)

print(tree_cnt)