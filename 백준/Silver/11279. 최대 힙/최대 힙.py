import sys
def heap_insert(myHeap:list, target:int):

    # index 를 1부터 시작하고 싶음 
    myHeap.append(target)

    cur_idx = len(myHeap) - 1   
    parent = cur_idx // 2 
    
    while( parent >= 1 and myHeap[parent] < myHeap[cur_idx]):
        myHeap[parent],myHeap[cur_idx] = myHeap[cur_idx],myHeap[parent]
        cur_idx = parent
        parent = cur_idx //2 
    
def max_heapify(myHeap:list, idx:int)->None:


    while( 2 * idx <= len(myHeap) - 1 ):
        next_idx = 2 * idx 
        if( 2 * idx + 1 <= len(myHeap) - 1):
            if(myHeap[2*idx] < myHeap[2*idx+1]):
                next_idx = 2*idx + 1 

        if(myHeap[idx] > myHeap[next_idx]):
           return
        
        myHeap[idx],myHeap[next_idx] = myHeap[next_idx],myHeap[idx]
        idx = next_idx

    return 

def heap_extract(myHeap:list)->int:

    cur_size = len(myHeap)
    ret = 0 

    if(cur_size == 1 ):
        return 0 
    
    myHeap[1],myHeap[-1] = myHeap[-1],myHeap[1]
    ret = myHeap[-1]
    myHeap.pop()
    max_heapify(myHeap,1)

    return ret 

EXTRACT = 0 
N = int(input())
target_heap = [0]
res = []

for idx in range(N):
    order = int(sys.stdin.readline())

    if( EXTRACT == order):
        res.append(heap_extract(target_heap))
        # print(target_heap.extract())
    else :
        heap_insert(target_heap,order)

print(*res,sep='\n')