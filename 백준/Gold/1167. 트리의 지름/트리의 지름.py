from collections import defaultdict
from collections import deque

V = int(input())
tree_info = [ list(map(int,input().split(' '))) for v in range(V)]
adj_graph = defaultdict(list)

for info in tree_info:
    s_node = info[0]
    e_node = 0

    for idx, item in enumerate(info[1:]):
        if(-1 == item):
            break
        if((idx % 2) == 0):
            e_node = item
        else:
            adj_graph[s_node].append((e_node, item))

def bfs(start_node:int):
    global adj_graph
    global V 

    last_e = 0
    last_w = 0
    q = deque([])
    visited = [False for _ in range(V+1)]
    visited[start_node] = True

    for adj_node, adj_weight in adj_graph[start_node]:
        visited[adj_node] = True 
        q.append([start_node,adj_node,adj_weight, 1])

    while( 0 < len(q)):

        s, e, w, cnt = q.pop()

        if(w > last_w):
            last_e = e
            last_w = max(last_w,w) 

        for adj_node, adj_weight in adj_graph[e]:
            
            if(True == visited[adj_node]):
                continue
            visited[adj_node] = True 
            q.append([e, adj_node, w + adj_weight, cnt + 1])
        
    return last_e, last_w

target_node, _ = bfs(1)
_, result = bfs(target_node)

print(result)