#include <cstdio>
#include <vector>
#include <queue>

#define INF 100001

using namespace std;

typedef struct Coord{
    int y,x;
}Coord;

int N;
int map[101][101];
int cost[101][101];
// {-1,1,0,0},{0,0,1,-1} 도 가능 ! .. 상관없다 
// 되돌아가면 cost값이 더 커지기 땜시 
int dirY[4] = {-1,0,1,0};
int dirX[4] = {0,1,0,-1};


bool isInMap(int y, int x) {
	if (y <= 0 || x <= 0 || y > N || x > N) {
		return false;
	}
	return true;
}
void bfs(int y, int x) {
	queue <Coord> q;
	q.push({ y,x });
	int curQsize = 0;
	while (q.empty() == false) {
		curQsize = q.size();
		for (int idx = 0; idx < curQsize; idx++) {
			Coord curCoord = q.front(); q.pop();
			int curY = curCoord.y;
			int curX = curCoord.x;
			for (int d = 0; d < 4; d++) {
				int nextY = curY + dirY[d];
				int nextX = curX + dirX[d];
				int nextCost = (cost[curY][curX] + map[nextY][nextX]);
				if ((isInMap(nextY, nextX) == true) && (cost[nextY][nextX] > nextCost)) {
					cost[nextY][nextX] = nextCost;
					q.push({ nextY,nextX });
				}
			}
		}
	}
}

int main(){
    int T = 0;
	int tc = 0;
	scanf("%d", &T);
	int y = 1, x = 1;
	for (tc = 1; tc <= T; tc++) {
		scanf("%d", &N);
		for (y = 1; y <= N; y++) {
			for (x = 1; x <= N; x++) {
				scanf("%1d", &map[y][x]);
                cost[y][x] = INF;
			}
		}
        cost[1][1]=0;
        bfs(1,1);
		printf("#%d %d\n", tc, cost[N][N]);
	}

	return 0;
}