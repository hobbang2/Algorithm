// [dijkstra algorithm 연습] swea1249_보급로
#include <cstdio>
#include <vector>
#include <queue>

#define INF 100001

using namespace std;

int N;
int map[101][101];
int dist[101][101];

int dirY[4] = { -1,0,1,0 };
int dirX[4] = { 0,-1,0,1 };

typedef struct Coord {
	int y, x;
	int w;
	bool operator > (const Coord & c)const {
		return w > c.w;
	}
}Coord;

bool isInMap(int y, int x) {
	if (y <= 0 || x <= 0 || y > N || x > N) {
		return false;
	}
	return true;
}

void dijkstraAlg(int y, int x) {
	priority_queue<Coord, vector<Coord>, greater<Coord>> pq;
	pq.push({ 1,1,0 });
	int pqSize = 0;
	while (pq.empty() == false) {
		pqSize = pq.size();
		for (int idx = 1; idx <= pqSize; idx++) {
			Coord curCoord = pq.top(); pq.pop();
			if (curCoord.y == N && curCoord.x == N) {
				return;
			}
			for (int d = 0; d < 4; d++) {
				int nextY = curCoord.y + dirY[d];
				int nextX = curCoord.x + dirX[d];
				if (isInMap(nextY, nextX) == true) {
					int nextValue = curCoord.w+map[nextY][nextX];
					if (dist[nextY][nextX] > nextValue) {
						pq.push({ nextY,nextX,nextValue});
						dist[nextY][nextX] = nextValue;
					}
				}
			}
		}
	}
}

int main() {
	int T = 0;
	int tc = 0;
	int answer = 0;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) {
		scanf("%d", &N);
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				scanf("%1d", &map[y][x]);
				dist[y][x] = INF;
			}
		}
		dist[1][1] = 0;
		dijkstraAlg(1, 1);
		printf("#%d %d\n", tc, dist[N][N]);
	}
	return 0;
}