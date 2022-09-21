#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int N = 0, M = 0;
	scanf("%d %d",&N, &M);
	vector <int> nums(N + 1, 0);
	vector <int> saveSum(N + 1, 0);

	for (int idx = 1; idx <= N; idx++) {
		scanf("%d", &nums[idx]);
	}

	saveSum[1] = nums[1];

	for (int idx = 2; idx <= N; idx++) {
		saveSum[idx] = saveSum[idx - 1] + nums[idx];
	}

	for (int m = 1; m <= M; m++) {
		int idx[2] = { 0, };
		scanf("%d %d", &idx[0], &idx[1]);
		printf("%d\n", saveSum[idx[1]] - saveSum[idx[0]-1]);
	}


	return 0;
}