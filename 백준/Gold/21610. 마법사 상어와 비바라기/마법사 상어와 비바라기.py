dr = [0, 0, -1, -1, -1, 0, 1, 1, 1  ] # 왼쪽부터 시계 방향
dc = [0, -1, -1, 0, 1, 1, 1, 0, -1  ] # 왼쪽부터 시계 방향

MAX_WATER = 1000
N, M = list(map(int, input().split(' ')))
game_map = [ list(map(int,input().split(' '))) for r in range(N)]
cloud_map = [ [ 0 for c in range(N)] for r in range(N)]

tmp_cloud_moving = [ list(map(int,input().split(' '))) for m in range(M)]
cloud_moving = [ [d, s % N] for d, s in tmp_cloud_moving]

# 비바라기 시전
cloud_list = [[N - 1, 0 ], [ N - 1, 1], [N-2, 0], [N-2, 1]]

for r, c in cloud_list:
    cloud_map[r][c] = 1

def is_in_map(r:int, c:int)->bool:

    if( ( r < 0 ) or ( c < 0)):
        return False

    if ((r >= N) or (c >= N ) ):
        return False

    return True

def move_cloud(dir:int, dist:int):

    new_cloud_list = []

    for cloud_r, cloud_c in cloud_list:

        next_r = (cloud_r + dr[dir] * dist + N ) % N
        next_c = (cloud_c + dc[dir] * dist + N ) % N

        if(False == is_in_map(next_r, next_c)):
            print(" error in " + next_r + next_c)
            exit(0)

        new_cloud_list.append([next_r, next_c])

    return new_cloud_list

def rainy_day():

    # 물 증가
    for r, c in cloud_list:
        cloud_map[r][c] = 1
        game_map[r][c] += 1

    return

# rainy day로 인해서 대각선 방향 바구니에 물이 생기는 경우가 있을 수 있음
# - rainy day가 실행된 후에 실행
def copy_water():

    for r, c in cloud_list:
        copy_water_cnt = 0
        # copy water
        # 물이 증가한 칸(구름이 있던 칸)에 대해 대각선 방향에 물이 있는 바구니 수만큼 다시 물 증가
        for dia_dir in range(2, 9 , 2):

            next_r = r + dr[dia_dir]
            next_c = c + dc[dia_dir]

            if(False == is_in_map(next_r, next_c)):
                continue
            # 대각선 바구니에 물이 없으면 다음 대각선 확인
            if(0 >= game_map[next_r][next_c]):
                continue

            copy_water_cnt += 1

        game_map[r][c] += copy_water_cnt
    return

def make_cloud()->list:

    # 기존 구름은 사라짐
    # 새로운 구름 생성
    new_cloud_list = []

    for r in range(N):
        for c in range(N):
            
            # 물 바구니에 물이 2 이상 담겨 있고 이번 턴에 구름이 사라진 칸이 아님
            if((game_map[r][c] >= 2) and (0 == cloud_map[r][c])):
                new_cloud_list.append([r,c])
                game_map[r][c] -= 2

    return new_cloud_list

def get_total_water()-> int:

    water_list = [ sum(game_map[r]) for r in range(N)]
    return sum(water_list)

def solution():

    global cloud_list, cloud_map

    # 구름 이동
    for d, s in cloud_moving:
        
        # 매 이동마다 cloud map 초기화
        cloud_map = [[0 for c in range(N)] for r in range(N)]
        cloud_list = move_cloud(d, s)
        rainy_day()
        copy_water()
        cloud_list = make_cloud()

    result = get_total_water()
    return result

print(solution())