# 1 <= N <= 10만 , 1<= M <=N
# 각 강의의 길이는 자연수 , < 10000
N,M = map( int, input().split(' '))
lencture_playtime_list = list(map(int, input().split(' ')))

# print( N , M , lencture_playtime_list)

# 최소 1 , 최대 < 100000
max_playtime = max(lencture_playtime_list)
lower_play_time = 1 
upper_play_time = sum(lencture_playtime_list)
answer = upper_play_time
# M 개의 블루레이 , 길이는 모두 같아야 하고 
# 녹화길이가 최소가 되면서 M 개에 나누어 남겨야 한다. 
while( lower_play_time <= upper_play_time ):
    mid_play_time = int( ( lower_play_time + upper_play_time ) / 2 )
    blueray_cnt = 1
    cur_blueray_playtime = 0
     
    for playtime in lencture_playtime_list:
        cur_blueray_playtime += playtime
        
        if( cur_blueray_playtime > mid_play_time ):
            blueray_cnt += 1 
            cur_blueray_playtime = playtime
            if( blueray_cnt > M ):
                break

    if( ( blueray_cnt > M ) or (mid_play_time < max_playtime) ):
        lower_play_time = mid_play_time + 1
    else :
        answer = min(answer , mid_play_time)
        upper_play_time = mid_play_time - 1

print(answer)
