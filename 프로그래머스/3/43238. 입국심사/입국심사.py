def solution(n, times):
    # 기다리는 사람 최대 10억명
    # 심사시간 최대 10억분
    # 심사관 10만명 이하
    times.sort()
    max_time = (times[-1] * n)
    min_time = 1
    answer = max_time + 1
    
    while min_time <= max_time:
        process_cnt = 0
        mid_time = (min_time + max_time) // 2
        
        for t in times:
            process_cnt += (mid_time // t)
            
        # 처리한 사람이 n명보다 많을 때
        if(process_cnt >= n):
            # 범위 좁혀서 다시 탐색
            answer = mid_time
            max_time = mid_time - 1
        # 처리한 사람이 n명보다 작을 때 또는 n명 일때
        else:
            # 대기시간을 늘려서 다시 탐색
            min_time = mid_time + 1
            
    
    return answer