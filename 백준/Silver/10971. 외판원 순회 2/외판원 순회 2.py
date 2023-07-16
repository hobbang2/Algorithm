import sys
input = sys.stdin.readline

N = int(input().strip())
city_map = [ list(map(int, input().strip().split(' '))) for _ in range(N)]
MAX_COST = 1000000 * 10 + 1
result = MAX_COST

def get_cost(visit_list:list, init_cost:int):
    
    global city_map
    cost_sum = init_cost
    
    for idx in range(N - 1):
        
        s_idx = visit_list[idx]
        e_idx = visit_list[idx + 1]
        cur_cost = city_map[s_idx][e_idx]

        cost_sum += cur_cost
        
    return cost_sum

# 완전 탐색으로 풀이
def trace_course(city_idx:int, cnt:int, visit_list:list):
    
    global city_map, N
    global result

    # 경로가 모두 만들어졌으면 비용을 구해줌
    if( ( N == cnt) ):
        
        start_idx = visit_list[0]
        last_idx  = visit_list[-1]
        init_cost = city_map[last_idx][start_idx]
        
        if( 0 == init_cost):
            return

        course_cost = get_cost(visit_list, init_cost)
        result = min(result, course_cost)
        return
        
    # 가능한 경로를 모두 만들어줌
    for next_idx in range(N):
        
        if( next_idx in visit_list):
            continue
        
        last_idx = visit_list[-1]
        
        # 불가능 경로
        if( 0 == city_map[last_idx][next_idx]):
            break
        
        visit_list.append(next_idx)
        trace_course(next_idx, cnt+1, visit_list)
        visit_list.pop()

    return 

for city_idx in range(N):
    
    trace_course(city_idx, 1, [city_idx])
    
print(result)