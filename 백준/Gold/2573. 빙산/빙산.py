import sys
input = sys.stdin.readline
import copy

N, M = map(int,input().split(' ')) # 행, 열
ice_mountain = [ list(map(int,input().split(' '))) for _ in range(N)]
ice_location = []
ice_cnt = 0

dn = [0, 0, 1, -1]
dm = [1, -1, 0, 0] # 동서남북

# 빙산이 어디에 있는지, 몇 개인지 확인 
for n in range(N):
    for m in range(M):
        if( 0 < ice_mountain[n][m] ):
            ice_location.append([n,m])
            ice_cnt += 1 

# 배열의 범위를 넘어가는지 확인 
def is_valid_loc(n, m):
    global ice_mountain
    global N
    global M 

    if( n < 0 or m < 0 ):
        return False 
    if( n >= N or m >= M):
        return False 
    return True

def bfs(init:list):
    global N
    global M

    visited = [ [False for _ in range(M)] for _ in range(N)]
    q = [init]
    cnt = 0

    while(q):
        cur_n, cur_m = q.pop(0)
        cnt += 1
        visited[cur_n][cur_m] = True 

        for d_idx in range(4):
            next_n = cur_n + dn[d_idx]
            next_m = cur_m + dm[d_idx]
            
            if( False == is_valid_loc(next_n, next_m)):
                continue 
            if(ice_mountain[next_n][next_m] == 0):
                continue 
            if(visited[next_n][next_m] == True ):
                continue 
            
            visited[next_n][next_m] = True 
            q.append([next_n,next_m])

    return cnt

# 얼음 녹이기
# 매년 얼음은 다 같이 녹기 때문에, 
# 해당 연도에 녹아서 0이 된 것은 다른 빙하를 녹일 때 영향을 주면 안됨 
def melt_ice():

    global ice_mountain
    global ice_location
    global ice_cnt

    cpy_ice_mountain = copy.deepcopy(ice_mountain)
    next_ice_location = []

    for ice_n, ice_m in ice_location:
        cnt = 0

        for d_idx in range(4):
            near_ice_n = ice_n + dn[d_idx]
            near_ice_m = ice_m + dm[d_idx]

            if( False == is_valid_loc(near_ice_n, near_ice_m)):
                continue
            if( 0 == cpy_ice_mountain[near_ice_n][near_ice_m]):
                cnt += 1
        
        if(ice_mountain[ice_n][ice_m] <= cnt):
            ice_mountain[ice_n][ice_m] =  0
            ice_cnt -= 1
        else: 
            ice_mountain[ice_n][ice_m] -= cnt
            next_ice_location.append([ice_n, ice_m])

    if( len(next_ice_location) == ice_cnt ):
        ice_location = copy.deepcopy(next_ice_location)

result = 0

while(1):
    
    if(ice_cnt <= 1):
        result = 0
        break

   # 빙산이 모두 연결되어 있다면 함수 실행의 결과가 남은 얼음의 수와 같아야 한다.
    if( ice_cnt != bfs(ice_location[0])):
        break

    result += 1 
    melt_ice()

 
print(result)