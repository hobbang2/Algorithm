N, M, L = map(int,input().split(' '))
rest_location = [0]

if(N > 0):
    rest_location = [0] + list(map(int, input().split(' ')))

rest_location.append(L)
rest_location.sort()
# mid length 만큼 휴게소를 짓는데
# M개를 초과하면 범위를 넓히고, M개보다 작거나 같으면 범위를 좁힌다 
start = 1
end = L - 1

while(start <= end):
    mid = (start + end) // 2
    installed_rest_cnt = 0
    rest_room_num = len(rest_location)

    for idx in range(1, rest_room_num):
        between_dist = rest_location[idx] - rest_location[idx - 1]
        installed_rest_cnt += (between_dist // mid)

        if( 0 == (between_dist % mid)):
            installed_rest_cnt -= 1

    # 설치된 개수가 더 많으면 간격을 늘려봐도 됨 
    if( installed_rest_cnt > M):
        start = mid + 1 

    # 설치된 개수가 더 적거나 같으면 간격을 좁혀보기
    else:
        end = mid - 1 
             
print(start)