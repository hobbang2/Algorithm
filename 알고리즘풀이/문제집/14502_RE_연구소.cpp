//20191017
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

enum{PATH,WALL,VIRUS,OCCUPY=7};
// 북동남서 
int dirY[4] = { -1,0,1,0 };
int dirX[4] = { 0,1,0,-1 };

typedef struct Coord {
	int y, x;
}Coord;

int N, M;
vector <vector <int> > originMap(9, vector <int>(9, 0));
queue <Coord> originVirus;
bool check[81];
int answer = -1;

bool isInMap(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M) {
		return false;
	}
	return true;
}

int spread(int zeroA) {
	vector <vector <int> > map(9, vector <int>(9, 0));
	queue <Coord> virusQ;
	map = originMap;
	virusQ = originVirus;

	while (virusQ.empty() == false) {
		if (zeroA <= answer) {
			break;
		}
		int qSize = (int)virusQ.size();
		for (int s = 0; s < qSize; s++) {
			Coord curVirus = virusQ.front(); virusQ.pop();
			for (int d = 0; d < 4; d++) {
				int nextY = curVirus.y + dirY[d];
				int nextX = curVirus.x + dirX[d];
				if ((isInMap(nextY, nextX) == true) && (map[nextY][nextX]==PATH)) {
					zeroA -= (map[nextY][nextX] == PATH);
					virusQ.push({ nextY,nextX });
					map[nextY][nextX] = OCCUPY;

				}
			}
		}
	}
	return zeroA;
}


void buildWALL(int idx, int cnt,int zeroArea) {
	if (idx > N * M || cnt > 3) {
		return;
	}
	if (cnt == 3) {
		int restArea = spread(zeroArea);
		answer = (answer < restArea) ? (restArea) : answer;
		return;
	}

	// 벽세우긩
	for (int curIdx = idx; curIdx < N*M; curIdx++) {
		int curY = curIdx / M;
		int curX = curIdx % M;
		if (originMap[curY][curX] == PATH)
		{
			originMap[curY][curX] = true;
			buildWALL(curIdx + 1, cnt + 1, zeroArea);
			originMap[curY][curX] = false;
		}
	}
	return;
}

int main() {
	scanf("%d %d", &N, &M);
	int zeroArea = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			scanf("%d", &originMap[y][x]);
			zeroArea += (originMap[y][x] == PATH);
			if (originMap[y][x] == VIRUS) {
				originVirus.push({ y,x });
				originMap[y][x] = OCCUPY;
			}
		}
	}
	buildWALL(0,0,zeroArea);
	printf("%d\n", answer-3);
	return 0;
}