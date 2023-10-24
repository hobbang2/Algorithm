import sys 
from collections import defaultdict
from collections import deque
from queue import PriorityQueue


input = sys.stdin.readline

N = int(input())
adj_graph = defaultdict(list)

for n in range(N - 1):
    s, e, w = map(int,input().split(' '))
    adj_graph[s].append((e,w))
    adj_graph[e].append((s,w))

def bfs(start_idx):
    
    q = deque()
    q.append([start_idx, 0])
    visited = [False] * (N + 1)
    visited[start_idx] = True
    ret_idx = -1
    ret_weight = 0

    while(q):
        s, cur_weight = q.pop()
        for e, next_weight in adj_graph[s]:
            if(True == visited[e]):
                continue
            visited[e] = True 
            q.append([e, cur_weight + next_weight])
            if(ret_weight < cur_weight + next_weight):
                ret_weight = cur_weight + next_weight
                ret_idx = e

    return ret_idx, ret_weight

target_idx, _ = bfs(1)
_, result  = bfs(target_idx)

print(result)