# 사용하고 있는 전기용품의 사용순서
# -> 플러그를 빼는 횟수 최소화

# 멀티탭 구명의 수 100이하, 전기용품의 총 사용횟수 100 이하 

import heapq
from collections import Counter

N,k = map(int,input().split(' ')) # 멀티탭의 구멍, 전기 용품의 총 사용 횟수
electron_usage = list(map(int,input().split(' ')))
electron_cnt = [0] * (k + 1)
b_electron_usage = [False] * (k+1)
idx_electron_usage = [-1] * (k+1)

# 뒤에서 사용할 제품을 안다.
# [ISSUE] 남은 횟수가 같을 때 먼저 사용하는 전자제품을 남겨둔다. 

for elec in electron_usage:
    electron_cnt[elec] += 1 

myHeap = []
result = 0 

for idx,elec in enumerate(electron_usage) : 
    # 사용 횟수 1 차감 
    electron_cnt[elec] -= 1 
    
    if( True == b_electron_usage[elec]):
        for item in myHeap :
            if(item[1] == elec and electron_cnt[elec] == 0):
                item[0] = -101
                heapq.heapify(myHeap)
                break
            
            elif(item[1] == elec and electron_cnt[elec] > 0):
                item[0] = -1 * electron_usage[idx + 1:].index(elec) - idx
                heapq.heapify(myHeap)
                break

        continue

    b_electron_usage[elec] = True 

    # 콘센트 하나 뽑아야 함
    # 가장 나중에 다시 등장하는 거 제거
    if len(myHeap) >= N:
        result += 1 
        remove_elec = heapq.heappop(myHeap)
        b_electron_usage[remove_elec[1]] = False

    if(electron_cnt[elec] > 0):
        heapq.heappush(myHeap,[-1 * electron_usage[idx + 1:].index(elec) - idx,elec])
    elif(electron_cnt[elec] == 0):
        heapq.heappush(myHeap,[-1 * 101,elec])  


print(result)