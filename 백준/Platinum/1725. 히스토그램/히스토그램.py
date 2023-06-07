from collections import deque

N = int(input())
cur_stack = [[int(input()),0]]
res = 0

for idx in range(1,N):
    
    cur_hist = int(input())
    cur_idx = idx 

    while( ( 0 < len(cur_stack) ) and cur_stack[-1][0] > cur_hist):
        
        hist_len, hist_idx = cur_stack.pop()
        res = max(res, (idx-hist_idx)*hist_len)
        cur_idx = min(cur_idx, hist_idx)
    
    if(  ( 0 == len(cur_stack) ) or (cur_hist !=  cur_stack[-1][0]) ):
        cur_stack.append([cur_hist,cur_idx])
    
while( 0 < len(cur_stack)):
    
    hist_len, hist_idx = cur_stack.pop()
    res = max(res, (N-hist_idx)*hist_len)

print(res)
