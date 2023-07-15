import sys 
from itertools import permutations
    
input = sys.stdin.readline

N = int(input().strip())
num_list = sorted(list(map(int,input().strip().split(' '))))
res = 0

for p in permutations(num_list):

    cur_sum = 0 

    for idx in range(N - 1):
        cur_sum += abs(p[idx] - p[idx + 1])
    
    res = max(res, cur_sum)
    
print(res)