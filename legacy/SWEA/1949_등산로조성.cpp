#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

enum {NORTH,EAST,SOUTH,WEST};
// 북동남서
int dirY[4] = { -1,0,1,0 };
int dirX[4] = { 0,1,0,-1 };
int N, k;
int answer = 0;
int maxH = -1;
int map[9][9];
int visited[9][9];

void cleaner() {
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));
	answer = 0;
	maxH = -1;
}

bool isInMap(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= N) {
		return false;
	}
	return true;
}

void buidRoad(int y, int x,int cnt) {
	for (int d = 0; d < 4; d++) {
		int nextY = y + dirY[d];
		int nextX = x + dirX[d];
		if ((isInMap(nextY, nextX) == true)&&(visited[nextY][nextX]==false) && (map[y][x] > map[nextY][nextX])) {
			visited[nextY][nextX] = true;
			buidRoad(nextY, nextX, cnt + 1);
			visited[nextY][nextX] = false;
		}
		else {
			answer = (answer < cnt) ? cnt : answer;
		}
	}
	return;
}

int main() {
	int T = 0, tc = 1;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) {
		scanf("%d %d", &N, &k);
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				scanf("%d", &map[y][x]);
				maxH = (maxH < map[y][x]) ? map[y][x] : maxH;
			}
		}

		for (int idx = 0; idx < N*N; idx++) {
			int y = idx / N;
			int x = idx % N;
			if (map[y][x] == maxH) {
				for (int cutIdx = 0; cutIdx < N*N; cutIdx++) {
					if (idx == cutIdx) {
						continue;
					}
					int cutY = cutIdx / N;
					int cutX = cutIdx % N;
					int tmpValue = map[cutY][cutX];
                    visited[y][x] = true;
                    for(int K = 0 ; K <k ;K++){
                        map[cutY][cutX] -=1;
    					buidRoad(y, x, 1);
                    }
					map[cutY][cutX] = tmpValue;
					visited[y][x] = false;
				}

			}
		}

		printf("#%d %d\n", tc, answer);
		cleaner();
	}
	return 0;
}