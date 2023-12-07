import sys
input = sys.stdin.readline

N, C = map(int,input().split(' '))
home_location = sorted([ int(input()) for _ in range(N)])
dist = [ ]
min_dist = 1
max_dist = home_location[-1] - home_location[0] 
# result = max_dist + 1
result = 1
rest_cnt = C

def install_wifi(target_dist:int):

    global home_location
    accum_dist = 0
    install_cnt = 0 

    for idx in range(1, N):
        accum_dist += home_location[idx] - home_location[idx - 1]

        if(accum_dist >= target_dist):
            install_cnt +=  1
            accum_dist = 0

    return install_cnt


while(min_dist <= max_dist):

    mid_dist = (min_dist + max_dist) // 2
    installed = 1
    installed += install_wifi(mid_dist)

    # 설치해야 할 공유기 수가 더 많으면 설치 범위를 좁혀서 다시 탐색
    if( rest_cnt > installed):
        max_dist = mid_dist - 1
    # 설치해야 할 공유기 수를 충족시키면 범위를 넓혀서 다시 탐색
    # result가 갱신됨 
    else:
        min_dist = mid_dist + 1
        result = max(result, mid_dist)

print(result)