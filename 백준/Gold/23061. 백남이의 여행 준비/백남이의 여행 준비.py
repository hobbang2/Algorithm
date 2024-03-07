import sys 
input = sys.stdin.readline

N, M = map(int,input().strip().split(' ')) # 물품 수, 가방 수
things = [list(map(int, input().strip().split(' '))) for _ in range(N)] # 물건의 무게와 가치 
bag_limit = [int(input().strip()) for _ in range(M)] # 가방이 견딜 수 있는 무게 
#효율성: (가방에 담긴 물건의 가치의 합) / 가방이 견딜 수 있는 최대 무게 

largest_limit = max(bag_limit)
dp = [0] * (largest_limit + 1)


# 물건 개수 만큼 순회
for idx in range(N):
    cur_w, cur_v = things[idx]

    for bag_w in range(largest_limit, 0, -1):

        if( bag_w + cur_w > largest_limit):
            continue 
        if( dp[bag_w] == 0):
            continue

        dp[bag_w + cur_w] = max(dp[bag_w + cur_w], dp[bag_w] + cur_v)

    # 이 물건 한 개만 담을 경우
    dp[cur_w] = max(dp[cur_w], cur_v)

efficiency = -1
result = -1

for idx, limit in enumerate(bag_limit):
    
    max_v = max(dp[:limit + 1])
    cur_eff = max_v / limit

    if efficiency < cur_eff:
        efficiency = cur_eff
        result = idx 

print(result + 1)