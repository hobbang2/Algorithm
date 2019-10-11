#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int N;
int map[101][101];
bool visited[101][101];
int cost[101][101];
// 이거 때메 개고생 ㅠ 
int dirY[4] = { -1,0,1,0 };
int dirX[4] = { 0,1,0,-1 };
int answer = 100001;

bool isInMap(int y, int x) {
	if (y <= 0 || x <= 0 || y > N || x > N) {
		return false;
	}
	return true;
}

void cleanVar(int & answer) {
	memset(map, 0, sizeof(map));
	memset(visited, false, sizeof(visited));
	memset(cost, 0, sizeof(cost));
	answer = 100001;
}

void recoverMap(int y, int x, int curCost) {
	if ((y == N) && (x == N)) {
		answer = (answer > curCost) ? curCost : answer;
		return;
	}
	if (answer < curCost) {
		return;
	}
	if ((cost[y][x] == 0)||(cost[y][x] > curCost)) {
		cost[y][x] = curCost;
	}
	else {
		return;
	}

	for (int d = 0; d < 4; d++) {
		int nextY = y + dirY[d];
		int nextX = x + dirX[d];
		if ((isInMap(nextY, nextX) == true) && (visited[nextY][nextX] == false)) {
			visited[nextY][nextX] = true;
			recoverMap(nextY, nextX, curCost + map[nextY][nextX]);
			visited[nextY][nextX] = false;
		}
	}
}

int main() {
	int T = 0;
	int tc = 0;
	scanf("%d", &T);
	int y = 1, x = 1;
	for (tc = 1; tc <= T; tc++) {
		scanf("%d", &N);
		for (y = 1; y <= N; y++) {
			for (x = 1; x <= N; x++) {
				scanf("%1d", &map[y][x]);
			}
		}
		visited[1][1] = true;
		recoverMap(1, 1, 0);
		printf("#%d %d\n", tc, answer);
        cleanVar(answer);
	}

	return 0;
}