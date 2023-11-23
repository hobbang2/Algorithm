N = int( input() )
num_arr = list(map(int,input().split(' ')))
dp = [ 0 for _ in range(N)]

dp[0] = 1 

for idx in range(1,N):
    dp_collect = []
    for ex_idx in range ( idx ) :
        if( num_arr[idx] > num_arr[ex_idx]):
            dp_collect.append(dp[ex_idx])
    
    if not dp_collect:
        dp[idx] = 1
    else:
        dp[idx] = max(dp_collect) + 1

print(max(dp))