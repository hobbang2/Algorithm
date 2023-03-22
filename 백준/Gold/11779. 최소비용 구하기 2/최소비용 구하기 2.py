import sys
import heapq 

input = sys.stdin.readline

INF = float('inf')

city_num = int(input())
bus_num = int(input())

adj = [[] for _ in range(city_num + 1)]
dist= [INF for _ in range(city_num + 1)]
path= [0 for _ in range(city_num + 1)]

for b in range(bus_num):
    s_city, e_city, cost = map(int,input().split(' '))
    adj[s_city].append([cost,e_city])
    path[e_city] = s_city # 이전 도시 기록
    
target_s, target_e = map(int,input().split(' '))

def dijkstra(start_v : int)->None : 
    
    pq = []
    dist[start_v] = 0 
    heapq.heappush(pq,[dist[start_v],start_v])
    
    while( len(pq) > 0):
        cur_cost, cur_v = pq[0]
        heapq.heappop(pq)
        
        # 해당 vertex 의 최소 비용이 갱신되지 않은 상태 
        if( cur_cost != dist[cur_v]):
            continue 
        
        # 인접 vertex 를 확인하면서 비용 갱신 
        for next_cost, next_v in adj[cur_v]:
            if(dist[next_v] <= cur_cost + next_cost ):
                continue 
            
            dist[next_v] = cur_cost + next_cost 
            heapq.heappush(pq, [dist[next_v], next_v])
            path[next_v] = cur_v 
    
    return 

# 방문한 도시가 역순으로 기록되어 반환되는 함수
def get_path_list(start_v:int, end_v:int)->list:
    
    ret = [end_v]
    
    # 출발 도시와 도착 도시가 같으면 움직이지 않는다.
    if( start_v == end_v):
        return [ret]
    
    next_v = end_v 
    
    while( start_v != path[next_v] ):
        
        ret.append(path[next_v])
        next_v = path[next_v]

    ret.append(start_v)
    
    return ret

dijkstra(target_s)
path_result = get_path_list(target_s,target_e)

print(dist[target_e])
print(len(path_result))

if( target_e == target_s ):
    print(target_e)
else :
    print(*path_result[::-1])
            
