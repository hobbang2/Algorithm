from collections import defaultdict
import sys
input = sys.stdin.readline

sys.setrecursionlimit(100010)
def get_parent(s, e):
    global N, parent_arr

    for next_node in adj_graph[s]:
        if((next_node == e) or (0 != parent_arr[next_node])):
            continue
        parent_arr[next_node] = s
        get_parent(next_node, s)

N = int(input())
parent_arr = [0] * (N + 1)
edges = [list(map(int,input().split())) for _ in range(N - 1)]
adj_graph = defaultdict(list)

for s, e in edges:
    adj_graph[s].append(e)
    adj_graph[e].append(s)

get_parent(1, -1)
for item in parent_arr[2:]:
    print(item)