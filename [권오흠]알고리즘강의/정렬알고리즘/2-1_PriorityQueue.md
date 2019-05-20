[참고강의 바로가기](https://bit.ly/2EgSX0G)

Heap sort는 heap(binary heap) 을 이용하여 sorting을 하는 알고리즘입니다. 

binary heap은 sort하는 것 외에도 중요한 용도를 가집니다. 

### Priority Queue  
Priority queue 는 max heap, min heap과 마찬가지로 Maximum Priority Queue 와 Minimunm Priority Queue로 나뉩니다.

이름이 **Priority Queue** 라서 왜인지 모르게 어렵게 느껴질 수도 있지만, 

우리가 흔히 사용하는 FIFO Queue 역시 *들어온 순서* 를 우선순위로 갖는 Priority Queue입니다.

**우선순위 큐**는 data를 담을 수 있는 container입니다. 

이렇게 담긴 data들을 꺼낼 때 우선순위가 높은 친구 먼저 꺼내게 됩니다. 

우선순위 큐를 구현하기 위해서는 다음과 같은 두가지 연산이 필요합니다.  
- Insert 
- Extract 

두 연산을 설명하기 앞서 상기 시킬 내용이 있습니다!
바로, Priority Queue 역시 Heap이기 때문에 두 가지 조건을 만족시켜야 함입니다.
1. Complete binary tree
2. Max/Min Heapify

#### InsertMaxHeap
insert 연산에서 complete binary tree 모양을 유지하는 가장 쉬운 방법은 

맨 마지막 node에 insert 할 값을 추가해주는 것입니다. 

그런데, 이렇게 추가해준 값이 parent의 것 보다 크다면 ? 

이런 문제가 있을 수 있으므로 추가한 값을 parent의 것과 비교해나가면서 parent보다 크다면 서로 바꿔주는 작업을 수행합니다.

```cpp
void user_Heap::insertData(int input_data)
{
	if (heap_size == MAX_HEAP_SIZE)
	{
		cout << "full of heap";
		return;
	}
	else
	{
		int cur_idx = heap_size++;
		int parent_idx = parent(cur_idx);
		data[cur_idx] = input_data;

		while ((cur_idx > 0) && (data[cur_idx] > data[parent_idx]))
		{
			user_swap(data[cur_idx], data[parent_idx]);
			cur_idx = parent_idx;
			parent_idx = parent(cur_idx);
		}
	}
}
```

#### ExtractMaxHeap
Extract 연산은 굉장히 간단합니다. 

Max heap에서 가장 큰 값(우선순위가 가장 높은 값)은 항상 root node에 위치합니다. 

따라서 이 root node의 값을 반환해주면 됩니다. 

그런데, Extract연산은 우선순위가 가장 높은 값을 반환하고 이 node를 삭제도 해주어야 합니다.

어떻게 하면 좋을까요?

Insert 연산처럼 가장 마지막 노드의 값을 root node에 대입합니다. 

이렇게 대입을 하고 나면, 역시나 root node는 heap property를 만족하지 못하게 됩니다. 

그런데 root node를 제외한 나머지 sub tree들은 모두 heap property를 만족하고 있네요 ! 

root node부터 Heapify 연산을 해줍시다 :>

```cpp
int user_Heap::extract()
{
	if (heap_size == 0)
	{
		cout << "Priority Queue is empty";
		return;
	}
	int top_priority_value = data[0];
	data[0] = data[heap_size--];
	maxHeapify(0);
	return top_priority_value;
}
```
