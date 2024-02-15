import heapq 

def solution(jobs):
    answer = 0
    
    pq_starttime = []
    pq_processtime = []
    
    # 진입 시간을 기준으로 priority queue
    for entry, process in jobs:
        heapq.heappush(pq_starttime, [entry, process])

    cur_time = 0
    result = 0 
    
    while( (len(pq_starttime) > 0)):
        
        # 현재 시간보다 진입 시간이 더 앞쪽에 있으면 process pq 삽입
        while( (len(pq_starttime) > 0) and
               (pq_starttime[0][0] <= cur_time) ):
            entry, process =  pq_starttime[0]
        
            if( entry <= cur_time):
                entry, process = heapq.heappop(pq_starttime)
                heapq.heappush(pq_processtime, [process, entry])
            
        process_cnt = len(pq_processtime)
        
        # 처리할게 없으면 시간만 1 증가
        if(0 == process_cnt):
            cur_time += 1
            
        # process pq에 아이템이 있으면 처리
        if((len(pq_processtime) > 0)):
            
            process, entry = heapq.heappop(pq_processtime)
            result += (cur_time - entry) + process # 대기시간 + 처리시간
            cur_time += process
            process_cnt = len(pq_processtime)
    
    while((len(pq_processtime) > 0)):
            
        process, entry = heapq.heappop(pq_processtime)
        result += (cur_time - entry) + process # 대기시간 + 처리시간
        cur_time += process
        process_cnt = len(pq_processtime)
        
    return result // len(jobs)