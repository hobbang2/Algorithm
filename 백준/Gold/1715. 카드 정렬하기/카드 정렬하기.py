from queue import PriorityQueue

N = int(input())
pq = PriorityQueue(maxsize=N)
card_arr = [ pq.put(int(input())) for _ in range(N)]

ret = 0

while 1 < pq.qsize() :
    next_elem = pq.get() + pq.get()
    ret += (next_elem)
    pq.put(next_elem)

print(ret)
