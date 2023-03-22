import heapq
import sys

input = sys.stdin.readline

INF = 300000 * 10 + 1 

V, E = map(int,input().split(' '))
adj = [dict() for _ in range(V+1)]
dist = [INF for _ in range(V+1)]

start_v = int(input())

for idx in range(E):
    s, e, cost = map(int,input().split(' '))
    
    if( ( e in adj[s] and adj[s][e] > cost ) or
          e not in adj[s]):
        adj[s][e] = cost
    
def dijkstra(start_v : int)->None : 
    
    pq = []
    dist[start_v] = 0 
    heapq.heappush(pq,[dist[start_v], start_v])
    
    while( len(pq) > 0 ):
        
        cur_cost, cur_v = pq[0]
        heapq.heappop(pq)
        
        if dist[cur_v] != cur_cost:
            continue
        
        for nxt_v in adj[cur_v]:
            nxt_cost = adj[cur_v][nxt_v]
             
            if( dist[nxt_v] <= cur_cost + nxt_cost ):
                continue 
            
            dist[nxt_v] = cur_cost + nxt_cost
            heapq.heappush(pq,[dist[nxt_v], nxt_v])
            
    return

dijkstra(start_v)

for elem in dist[1:]:
    v = 'INF' if elem == INF else str(elem)
    print(v)