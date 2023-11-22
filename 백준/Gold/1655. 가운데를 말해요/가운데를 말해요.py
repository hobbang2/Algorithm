import heapq
import sys
input = sys.stdin.readline

N = int(input())
leftheap = [] # 중앙값 기준 왼쪽 숫자들이 담길 힙 : 최대 우선 순위
rightheap = [] # 중앙값 기준 오른쪽 숫자들이 담길 힙 : 최소 우선 순위 
result = []
for idx in range(N):

    cur_num = int(input())

    if( (len(leftheap)) == (len(rightheap))):
        heapq.heappush(leftheap, (-cur_num,cur_num))
    else:
        heapq.heappush(rightheap, (cur_num, cur_num))

    if rightheap and leftheap[0][1] > rightheap[0][0]:
        min_value = heapq.heappop(rightheap)[0]
        max_value = heapq.heappop(leftheap)[1]
        heapq.heappush(leftheap, (-min_value, min_value))
        heapq.heappush(rightheap, (max_value, max_value))
    
    result.append(leftheap[0][1])

print(*result)
    
