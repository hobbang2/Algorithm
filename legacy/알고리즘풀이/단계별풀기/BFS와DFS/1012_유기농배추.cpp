#include <cstdio>
#include <cstring>

int N, M;
int map[51][51] = { 0, };
int dirY[4] = { -1,0,1,0 };
int dirX[4] = { 0,1,0,-1 };
void cleaner() {
	memset(map, 0, sizeof(map));
}

bool isInRange(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= M) {
		return false;
	}
	return true;
}

void getArea(int y, int x,int cnt) {
	int nextY = 0, nextX = 0;
	for (int d = 0; d < 4; d++) {
		nextY = y + dirY[d];
		nextX = x + dirX[d];
		if ((isInRange(nextY, nextX) == true) && (map[nextY][nextX] == 1)) {
			map[nextY][nextX] = cnt;
			getArea(nextY, nextX, cnt);
		}
	}
}

int main() {
	int T = 0; 
	int answer = 0;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		int num = 0;
		scanf("%d %d %d", &M, &N, &num);
		int  y = 0, x = 0;
		for (int n = 0; n < num; n++) {
			scanf("%d %d", &x, &y);
			map[y][x] = 1;
		}

		int cnt = 2;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (map[y][x] == 1) {
					map[y][x] = cnt;
					getArea(y, x, cnt);
					cnt += 1;
				}
			}
		}
		printf("%d\n", cnt - 2);
		cleaner();

	}
	return 0;
}