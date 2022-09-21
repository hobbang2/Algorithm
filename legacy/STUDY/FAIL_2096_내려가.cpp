#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// 아래,왼쪽,오른쪽
int dir_x[3] = {0,-1,1};
int dir_y[3] = {1,1,1};
int N;

void findMinValue(int y, int curIdx) {
	for (int dir = 0; dir < 3; dir++) {
		int nextIdx = curIdx + dir_x[dir];
		if (nextIdx < 0 || nextIdx >= N) {
			continue;
		}

	}
}



int main() {
	scanf("%d", &N);
	vector <vector <int> > map(N, vector<int>(N, 0));

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &map[y][x]);
		}
	}

	int minValue = 987654321;
	int maxValue = -1;
	int minSum = 0;
	int maxSum = 0;
	int minIdx = -1;
	int maxIdx = -1;


	for (int x = 0; x < N; x++) {
		if (map[0][x] < minValue) {
			minValue = map[0][x];
			minIdx = x;
		}
		if (map[0][x] > maxValue) {
			maxValue = map[0][x];
			maxIdx = x;
		}
	}

	minSum += minValue;
	maxSum += maxValue;

	for (int y = 1; y = N; y++) {
		int curMinSum = 0;
		int curMaxSum = 0; 
		int exMinSum = 0;
		int exMaxSum = 0;
		for (int dir = 0; dir < 3; dir++) {
			curMinSum = minSum;
			int nextMinIdx = minIdx + dir_x[dir];
			if (nextMinIdx < 0 || nextMinIdx >= N) {
				continue;
			}
			curMin 
			
		}
	}


	printf("%d %d\n", maxSum, minSum);

	return 0;
}