# import sys
# input = sys.stdin

N, D = map(int, input().split(' '))
dp = [ idx for idx in range(D + 1)]

path_list = [list(map(int, input().split(' '))) for n in range(N)]
path_list.sort() 

for p in path_list:
    # s, e, cost = map(int,input().split(' '))
    s, e, cost = p
    
    if( s > D or e > D ):
        continue 
    
    dp[e] = min(dp[e], dp[s] + cost)
    
    for next_idx in range(e+1, D + 1):
        dp[next_idx] = min( dp[next_idx], dp[next_idx - 1] + 1)
        
print(dp[D])