/*
[merge sort]
시간복잡도 : O(nlogn)
- 분할 : 해결하고자 하는 문제를 '작은 크기의 동일한 문제'들로 분할 ★동일한★
- 정복 : 각각의 작은 문제를 순환적으로 해결
- 합병 : 작은 문제의 해를 합하여(merge) 원래 문제에 대한 해를 구함
본질적으로 recusion을 이용한 문제해결 
정렬된 리스트를 담을 추가배열이 필요하기 때문에 많은 memory가 필요한 것이 단점 
*/

#include <iostream>
#include <vector>
#include <ctime>
#include <random>


using namespace std;
void mergeSort(vector<int> & arr, int p, int r);
void Merge(vector<int> & arr, int p, int q, int r);
void initVec(vector <int> & for_);

vector <int> tmp_arr(100, 0);

int main()
{
	srand(time(nullptr));
	vector <int> data(100, 0);
	for (int i = 0; i < 100; i++)
	{
		data[i] = rand()%100 +1;
	}
	/*for (auto iter = data.begin(); iter != data.end(); iter++)
	{
		cout << *iter << " ";
	}*/

	for (int i = 0; i < 100; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl<<endl;
	
	mergeSort(data, 0, 99);

	for (auto iter = data.begin(); iter != data.end(); iter++)
	{
		cout << *iter << " ";
	}
  
  initVec(data);
  initVec(tmp_arr);
	return 0;
}

void mergeSort(vector<int> & arr, int p, int r)
{
	//base case : p >= r -> list의 크기가 1이거나 0 => 종료 
	if (p >= r)
	{
		return;
	}

	else
	{
		// q 는 p와 r의 중간 
		int q = (p + r) >> 1;
		mergeSort(arr, p, q);
		mergeSort(arr, q + 1, r);
		Merge(arr, p, q, r);
	}
}
void Merge(vector <int> & for_merge, int p, int q, int r)
{
	int i = p, j = q + 1, k = p;
	while (i <= q && j <= r)
	{
		if (for_merge[i] <= for_merge[j])
		{
			tmp_arr[k++] = for_merge[i++];
		}
		else
		{
			tmp_arr[k++] = for_merge[j++];
		}
	}

	while (i <= q)
	{
		tmp_arr[k++] = for_merge[i++];
	}

	while (j <= r)
	{
		tmp_arr[k++] = for_merge[j++];
	}

	for (int i = p; i <= r; i++)
	{
    for_merge[i] = tmp_arr[i];
  }
}

void initVec(vector <int> & for_)
{
    vector <int> emp;
    for_.swap(emp);
}
