import sys

from collections import defaultdict
from collections import deque

input = sys.stdin.readline

class DisjointSet:
    
    def __init__(self, n):
        self.parent = [ idx for idx in range(n+1)]
        self.rank = [ 1 for idx in range(n + 1)]

    def find(self, vertex:int):
        if(vertex == self.parent[vertex]):
            return vertex
        
        self.parent[vertex] = self.find(self.parent[vertex])
        return self.parent[vertex]
    
    def merge(self, s, e):
        s = self.find(s); e = self.find(e)
        if( s == e): return 
        if(self.rank[s] > self.rank[e]):
            s, e = e, s
        self.parent[s] = e
        if(self.rank[s] == self.rank[e]):
            self.rank[e] += 1
        return 
    
V, E = map(int,input().split(' '))
adj_graph = defaultdict(list)
edge_info = []

for e in range(E):
    s, e, w = map(int, input().split(' '))
    adj_graph[s].append([w, e])
    adj_graph[e].append([w, s])
    edge_info.append([w,(s, e)])

for k in adj_graph.keys():
    adj_graph[k].sort()

edge_info.sort(key=lambda x : x[0])
ret = 0 
sets = DisjointSet(V)

for edge in edge_info:
    cost, (s, e) = edge
    if(sets.find(s) == sets.find(e)):
        continue
    sets.merge(s, e)
    ret += cost

print(ret)