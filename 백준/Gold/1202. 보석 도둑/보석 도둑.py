import sys
import heapq

N, K = list(map(int,(sys.stdin.readline().split(' '))))
gemstone_heap = []

for _ in range (N):
    heapq.heappush(gemstone_heap,list(map(int,sys.stdin.readline().split(' '))))

bag_arr = [int(sys.stdin.readline()) for _ in range(K)]
bag_arr.sort()

ret = 0 

tmp_heap = []

for bag in bag_arr :
    # 보석의 무게가 가방 무게 보다 작을 경우
    # 가방에 담길 보석의 대상이 된다.
    # 뒷 차례 가방에 담길 보석의 대상도 누적됨
    while gemstone_heap and bag >= gemstone_heap[0][0]:
        heapq.heappush(tmp_heap, -heapq.heappop(gemstone_heap)[1])
    
    # 가방에 담길 보석 후보가 있으면 결과 값에 더해준다. 
    if(tmp_heap):
        ret -= heapq.heappop(tmp_heap)
    # 가방에 담길 보석 후보가 없고 확인할 보석도 없으면 끝 
    elif not gemstone_heap:
        break

    

print(ret)
