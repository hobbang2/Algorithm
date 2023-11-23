import sys 
input = sys.stdin.readline

N = int(input())
initial_list = list(map(int,input().split(' ')))
front_of_children = [0 for _ in range(N + 1)]

for c_num in initial_list:
    front_of_children[c_num] = front_of_children[c_num - 1] + 1 

print(N - max(front_of_children))