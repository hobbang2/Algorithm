#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int dirY[4] = { 0,1,0,-1 };
int dirX[4] = { 1,0,-1,0 };
int map[11][11];

bool isInMap(const int & y, const int & x,const int & N) {
	if (y < 0 || x < 0 || y >= N || x >= N) {
		return false;
	}
	return true;
}

void getDal(const int & n) {
	int curDir = 0;
	int y = 0, x = 0;
	int nextY = 0, nextX = 0;
	int range = n * n;

	for (int r = 1; r <= range; r++) {
		map[y][x] = r;
		if (r == range) {
			break;
		}
		nextY = y + dirY[curDir];
		nextX = x + dirX[curDir];
		if ((isInMap(nextY, nextX, n) == false) || (map[nextY][nextX] != 0)) {
			curDir = (curDir + 1) % 4;
			nextY = y + dirY[curDir];
			nextX = x + dirX[curDir];
		}
		y = nextY;
		x = nextX;
	}
	return;
}

int main() {
	int T = 0;
	int tc = 0;
	int answer = 0;
	int N = 0;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) {
		scanf("%d", &N);
		getDal(N);
		printf("#%d\n", tc);
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				printf("%d ", map[y][x]);
			}
			printf("\n");
		}
		memset(map, 0, sizeof(map));
	}
	return 0;
}