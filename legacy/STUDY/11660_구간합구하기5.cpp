#include <cstdio>
#include <vector>

using namespace std;
int square[1025][1025];
int saveSum[1025][1025];
int main() {

	int N = 0, M = 0;
	scanf("%d %d", &N, &M);

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			scanf("%d", &square[y][x]);
			saveSum[y][x] = saveSum[y - 1][x] + saveSum[y][x - 1] - saveSum[y - 1][x - 1] + square[y][x];
		}
	}

	while (M--) {
		int idx[4] = { 0, };
		scanf("%d %d %d %d", &idx[1], &idx[0], &idx[3], &idx[2]);
		int answer = saveSum[idx[3]][idx[2]] - saveSum[idx[3]][idx[0] - 1] - saveSum[idx[1] - 1][idx[2]] + saveSum[idx[1]-1][idx[0]-1];
		printf("%d\n", answer);
	}


	return 0;
}