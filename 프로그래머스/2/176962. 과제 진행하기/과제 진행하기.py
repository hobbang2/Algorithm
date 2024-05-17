from collections import deque

def solution(plans):
    answer = []
    plan_info = [ [*list(map(int,p[1].split(':'))),
                   int(p[2]), \
                   p[0] ] for p in plans]
    plan_info_dq = deque(sorted(plan_info, key=lambda x: (x[0], x[1])))
    wait_dq = deque()
    
    curh, curm, tick, name = plan_info_dq.popleft()
    
    while((len(plan_info_dq) > 0 )):

        advh, advm, advtick, advname = plan_info_dq[0]

        curm += 1
        tick -= 1 
        
        if(curm == 60):
            curh += 1
            curm = 0 
            
        if((curh == advh) and (curm == advm) ):
            # 과제 시간이 남았는데 새로운 과제를 해야한다.
            if(tick > 0):
                wait_dq.append([tick, name])
            # 과제 끝과 맞물림
            else:
                answer.append(name)
            # 새과제 시작
            curh, curm, tick, name = plan_info_dq.popleft()
        
        # 시작할 새 과제가 없고 현재 과제 끝남
        elif(tick == 0):
            answer.append(name)
            # 대기열에 과제가 있으면 가장 최근 것부터 다시 진행
            if((len(wait_dq) > 0)):
                tick, name = wait_dq.pop()
            # 대기열에도 없으면 새로 꺼내자
            else:
                curh, curm, tick, name = plan_info_dq.popleft()


    # 과제 수행시간이 남은 경우
    if tick > 0:
        answer.append(name)
    
    # 대기열 과제 완료하기
    while(len(wait_dq) > 0 ):
        t, n = wait_dq.pop()
        answer.append(n)
        
    return answer