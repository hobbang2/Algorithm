import heapq
import sys 
input = sys.stdin.readline
INF = float('inf')

N, E = map(int, input().split()) # 정점, 간선 
adj = [dict() for _ in range(N+1)]

for e in range(E):
    s, e, cost = map(int,input().split())
    # 연결이 안된 지점이거나 cost 가 더 낮으면 갱신 
    if ( e not in adj[s] ) or ( e in adj[s] and cost < adj[s][e]):
        adj[s][e] = cost
        # 양방향이므로 함께 갱신 
        adj[e][s] = cost
    
# v1 != v2, v1 != N, v2 != 1 
v1, v2 = map(int,input().split())

def dijkstra(start_v:int)->list:
    dist = [INF for _ in range(N+1)]
    
    pq = []
    # 매 dijkstra 마다 dist 배열이 초기화 되어 있어야 한다. 
    dist[start_v] = 0 
    heapq.heappush(pq, [dist[start_v],start_v])
    
    while( len(pq) > 0):
        
        cur_cost, cur_v = heapq.heappop(pq)
        
        # 최소 cost 가 갱신되지 않은 지점이라면 넘어간다.
        if( dist[cur_v] != cur_cost):
            continue

        for next_v in adj[cur_v]:
            next_cost = adj[cur_v][next_v]
            
            if( dist[next_v] <= cur_cost + next_cost):
                continue
            
            dist[next_v] = cur_cost + next_cost 
            heapq.heappush(pq,[dist[next_v], next_v])
    
    return dist

# path1_dist = dijkstra(v1)
# path2_dist = dijkstra(v2)

# print(path1_dist)
# print(path2_dist)
# cost = min(path1_dist[1], path2_dist[1] ) + min(path1_dist[v2], path2_dist[v1] ) + min(path1_dist[N], path2_dist[N] ) # 1

path1_dist = dijkstra(1)
path2_dist = dijkstra(v1)
path3_dist = dijkstra(N)

# cost = min(path1_dist[v1], path1_dist[v2] ) + path2_dist[v2] + min(path3_dist[v1], path3_dist[v2] ) # 1
cost = min(path1_dist[v1] + path2_dist[v2]+ path3_dist[v2], path1_dist[v2] + path2_dist[v2]+ path3_dist[v1] ) # 1

cost = -1 if( INF <= cost) else cost 

print(cost)
