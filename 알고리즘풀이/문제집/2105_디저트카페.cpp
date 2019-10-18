#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int dirY[4] = { 1,1,-1,-1 };
int dirX[4] = { -1,1,1,-1 };

typedef struct Coord {
	int y, x;
	int dir;
}Coord;

int N;
int answer;
int map[21][21];
int kind[101];

int CHECK;

bool isInMap(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= N) {
		return false;
	}
	return true;
}

void cafeTour(int originY, int originX, int y, int x, int dir, int cnt, int wind) {
	if (dir == 4) {
		if ((originY == y) && (originX == x)) {
			int de = 0;
			for (int i = 1; i <=100; i++) {
				if (kind[i] == 1) {
					de += (1);
				}
			}
			answer = (answer < de) ? (de) : (answer);
		}
		return;
	}
	int k = map[y][x];
	int nextY = y + dirY[dir];
	int nextX = x + dirX[dir];

	kind[k] = 1;
	if ((isInMap(nextY, nextX) == true) && (kind[map[nextY][nextX]] == 0)) {
		cafeTour(originY, originX, nextY, nextX, dir, cnt + 1, wind);
		cafeTour(originY, originX, nextY, nextX, dir + 1, cnt + 1, wind);
	}
	else {
		cafeTour(originY, originX, y, x, dir + 1, cnt + 1, wind);
	}
	kind[k] = 0;
	return;
}


int main() {
	int T = 0, tc = 1;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) {
		scanf("%d", &N);
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				scanf("%d", &map[y][x]);
			}
		}

		for (int idx = 0; idx < N*N; idx++) {
			int y = idx / N;
			int x = idx % N;
			int startY = y + dirY[0], startX = x + dirX[0];
			int landY = y + dirY[1], landX = x + dirX[1];
			if ((isInMap(startY, startX) && isInMap(landY, landX))) {
				cafeTour(landY, landX, y, x, 0, 0, 1);
			}
		}
		answer = (answer < 4) ? -1 : answer;
		printf("#%d %d\n", tc, answer);
		memset(kind, 0, sizeof(kind));
		answer = 0;
	}

	return 0;
}