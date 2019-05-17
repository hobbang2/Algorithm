/*
HeapSort
1. Complete binary tree
2. heap property 만족 ( 부모 >= 자식 OR 부모 <= 자식)
------------------------------------------------------------------
heap_property를 만족시켜주는 함수 
-> max_heapify
전제조건) root node를 제외한 나머지 node들은 모두 heap이다. 
=> 가장 마지막 root node부터 시작 ! 
*/


#include <iostream>

using namespace std;

int my_random(int r)
{
	int x = 987654321;
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return (x % r)+1;
}

void user_swap(int & f, int & s)
{
	int cpy_f = 0;
	cpy_f = f;
	f = s;
	s = cpy_f;
	return;
}

void maxHeapify(int data[], int data_size, int root_idx)
{
	int l_idx = 2 * root_idx + 1;
	int r_idx = 2 * root_idx + 2;
	int p_idx = root_idx;

	// left child 와 right child 중 더 큰 값이 새로운 parent가 됨 
	if ((l_idx <= data_size) && (data[l_idx] > data[p_idx]))
	{
		p_idx = l_idx;
	}
	if ((r_idx <= data_size) && (data[r_idx] > data[p_idx]))
	{
		p_idx = r_idx;
	}
	if (p_idx == root_idx)
	{
		return;
	}
	user_swap(data[root_idx], data[p_idx]);
	maxHeapify(data, data_size, p_idx);
}

// heap을 구성한다. 
void buildMaxHeap(int data[], int size)
{
  // for문 조건 주의 'ㅅ'
	for (int parent = size / 2; parent >= 0; parent--)
	{
		maxHeapify(data, size, parent);
	}
}
void heapSort(int data[], int size)
{
	buildMaxHeap(data, size);
	for (int i = size; i > 0;)
	{
		user_swap(data[0], data[i]);
		i--; // 가장 큰 값을 맨 끝으로 보내버리고 heap size를 줄인다.(정렬된 것으로 간주, heap에서 제외)
		maxHeapify(data, i, 0); // root node에 대하여 heapify
	}
}

int main()
{
	int arr[100] = {0,};
	int max_data_len = sizeof(arr) / sizeof(arr[0]);

	for (int idx = 0; idx < max_data_len; idx++)
	{
		arr[idx] = my_random(idx+1); // 1) complete binary tree 만족
	}

	// 배열의 index는 0부터 시작해서 n-1까지 이므로 
	// maximum lenth에서 1을 뺀 값을 전달한다. 
	heapSort(arr, max_data_len-1);

	for (int idx = 0; idx < max_data_len; idx++)
	{
		cout << arr[idx] << " ";
	}

	return 0;
}
