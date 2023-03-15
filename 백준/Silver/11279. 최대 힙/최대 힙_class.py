class MyMaxHeap:
    
    def __init__(self, max_size:int, target_list:list=[]):
        self.max_size = max_size 
        self.cur_size = 0
        self.Heap = [0] * (self.max_size + 1 )
        self.FRONT = 1 

        # if 0 < len(target_list) and max_size != len(target_list) :
        #     print("target_list size must be same with max_size parameter")
            
        # elif 0 < len(target_list):
        #     self.Heap = target_list
        #     for i in range ( max_size // 2, 0 , -1):
        #         self.heapify(i)
                
        return 

    # 부모 노드의 값은 자식 노드의 값보다 크거나 같다.
    def heapify(self, idx):
        # index 가 1부터 시작하므로 배열의 마지막 index 는 max_size 와 같다. 
        # 자식 노드가 있을 때 까지 
        while( 2*idx <= self.cur_size):
            k = 2 * idx 
            if( 2*idx + 1 <= self.cur_size):
                k = 2 * idx if self.Heap[2*idx] > self.Heap[2*idx + 1] else 2 * idx + 1 
            
            if self.Heap[idx] > self.Heap[k]:
                return
            
            self.Heap[idx], self.Heap[k] = self.Heap[k],self.Heap[idx]
            idx = k
    
    def insert(self,item):

        if(self.max_size <= self.cur_size):
            print("[ERROR] size error")
            return
        
        self.cur_size += 1
        self.Heap[self.cur_size] = item

        cur_idx = self.cur_size
        parent_idx = cur_idx// 2 

        while( parent_idx >= 1 and self.Heap[parent_idx] < self.Heap[cur_idx]):
            self.Heap[parent_idx],self.Heap[cur_idx]  = self.Heap[cur_idx],self.Heap[parent_idx]
            cur_idx = parent_idx
            parent_idx = cur_idx // 2

    def extract(self):
        if(self.cur_size <= 0 ):
            return 0
        ret = self.Heap[self.FRONT]
        self.Heap[self.cur_size],self.Heap[self.FRONT] = self.Heap[self.FRONT], self.Heap[self.cur_size]
        self.cur_size -= 1 
        
        # for i in range ( self.cur_size // 2, 0 , -1):
        #     self.heapify(i)
        self.heapify(1)
        return ret

def main():
    EXTRACT = 0 
    N = int(input())
    target_heap = MyMaxHeap(N)
    res = []

    for idx in range(N):
        order = int(input())
        if( EXTRACT == order):
            res.append(target_heap.extract())
            # print(target_heap.extract())
        else :
            target_heap.insert(order)

    print(*res,sep='\n')
    
if __name__ == "__main__":
    main() 
