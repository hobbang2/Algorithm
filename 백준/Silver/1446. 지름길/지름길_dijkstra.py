import heapq

# dijkstra : 한 정점에서 나머지 모든 정점까지의 거리 
N, D = map(int, input().split(' '))
INF = 2 * D 

dist = [ idx for idx in range(D+1)]
dist[0] = 0 
adj = [[] for idx in range(D+1)] 

pq = []

for n in range(N):
    s, e, cost = map(int, input().split(' '))
    # 도착 지점을 넘어가도록 제공되면 edge를 추가하지 않는다.
    if(s > D or e > D):
        continue
    adj[s].append([cost, e])

# 단방향 연결을 만들어준다.
for d in range(1,D+1):
    adj[d-1].append([1,d])
        
def dijkstra(s_vertex : int) -> None : 
    
    dist[s_vertex] = 0 
    heapq.heappush(pq, [dist[s_vertex], s_vertex])
    
    while( len(pq) > 0 ):
        
        cost, v = pq[0]
        heapq.heappop(pq)    
        
        if( cost != dist[v]):
            continue 
        
        for elem in adj[v]:
            next_cost, next_v = elem 
            if(dist[next_v] < dist[v] + next_cost):
                continue 
            
            dist[next_v] = dist[v] + next_cost 
            heapq.heappush(pq, [dist[next_v], next_v])
            
dijkstra(0)
print(dist[D])
