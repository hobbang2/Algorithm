// union find 는 부품처럼 쓰이닊.... 잘 알아두ㅈ ㅏ !  
#include <cstdio>
#include <vector>

using namespace std;

void user_union(vector <int>& _nums,int target[]) {
	int cpyTarget[2] = { target[0],target[1] };
	while (cpyTarget[0] != _nums[cpyTarget[0]]) {
		cpyTarget[0] = _nums[cpyTarget[0]];
	}
	while (cpyTarget[1] != _nums[cpyTarget[1]]) {
		cpyTarget[1] = _nums[cpyTarget[1]];
	}


	int dist = cpyTarget[0] < cpyTarget[1] ? cpyTarget[0] : cpyTarget[1];
	_nums[target[0]] = dist;
	_nums[target[1]] = dist;
	
	// 최종 root의 것도 바꾸어주어야함 
	if (cpyTarget[0] < cpyTarget[1]) {
		_nums[cpyTarget[1]] = dist;
	}
	else {
		_nums[cpyTarget[0]] = dist;
	}
	
	return;
}

bool isIncluded(vector <int> &_nums,int target[]) {
	int cpyTarget[2] = { target[0],target[1] };

	/*
	int function(int num){
	    if(parent[num] == num) return num;
		else parent[num]= function(parent[num]);
	
	*/
	while (cpyTarget[0] != _nums[cpyTarget[0]]) {
		cpyTarget[0] = _nums[cpyTarget[0]];
	}
	while (cpyTarget[1] != _nums[cpyTarget[1]]) {
		cpyTarget[1] = _nums[cpyTarget[1]];
	}


	if (cpyTarget[0] == cpyTarget[1]) {
		return true;
	}
	else {
		return false;
	}
}


int main() {
	int N = 0, M = 0;
	scanf("%d %d", &N, &M);
	vector <int> nums(N+1, 0);
	for (int idx = 1; idx < N +1; idx++) {
		nums[idx] = idx;
	}

	while (M--) {
		int order = 0;
		int target[2] = { 0, };
		scanf("%d %d %d", &order, &target[0], &target[1]);
		getchar();

		switch(order) {
			case 0:
				user_union(nums,target);
				break;
			case 1:
				if (isIncluded(nums,target)) {
					printf("YES\n");
				}
				else {
					printf("NO\n");
				}
				break;
			default:
				break;
		}
	}
	return 0;
}