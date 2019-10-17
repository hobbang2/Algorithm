#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

enum {PATH,WALL,VIRUS,OCCUPY=7};

typedef struct Coord {
	int y, x;
}Coord;

int virusLoc = 0;
int answer = 3000;
int dirY[4] = { -1,0,1,0 };
int dirX[4] = { 0,1,0,-1 };
int N, numOfVirus;
int map[51][51];
int originMap[51][51];
vector <int> virusVec;
vector <bool> check(11, false);

bool isInMap(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= N) {
		return false;
	}
	return true;
}

void spread(queue <int> & virusQ,int zeroA) {
	int depth = 0;
	while (virusQ.empty() == false) {
		int qSize = (int)virusQ.size();
		if (zeroA <= 0) {
			break;
		}
		depth += 1;
		for (int q = 0; q < qSize; q++) {
			int curCoord = virusQ.front(); virusQ.pop();
			int curY = curCoord / 53;
			int curX = curCoord % 53;
			for (int d = 0; d < 4; d++) {
				int nextY = curY + dirY[d];
				int nextX = curX + dirX[d];
				if ((isInMap(nextY, nextX) == true) && (map[nextY][nextX] != WALL)&& (map[nextY][nextX] != OCCUPY)) {
					map[nextY][nextX] = OCCUPY;
					virusQ.push(nextY * 53 + nextX);
					zeroA -= 1;
				}
			}
		}
	}
	if (zeroA <= 0) {
		answer = (answer > depth) ? depth : answer;
	}
}

void releaseVirus(int idx, int cnt, int zeroA) {
	if (idx > (virusLoc) || cnt > (numOfVirus)) {
		return;
	}
	if (cnt == numOfVirus) {
		memcpy(map, originMap, sizeof(originMap));
		queue <int> virusQ;
		for (int c = 0; c < virusLoc; c++) {
			if (check[c] == true) {
				int curY = virusVec[c] / 53;
				int curX = virusVec[c] % 53;
                // 방문체크 주의 
				map[curY][curX] = OCCUPY;
				virusQ.push(virusVec[c]);
			}
		}
		spread(virusQ,zeroA);
		return;
	}
	for (int curIdx = idx; curIdx < virusLoc; curIdx++) {
		check[curIdx] = true;
		releaseVirus(curIdx + 1, cnt + 1, zeroA);
		check[curIdx] = false;
	}
}


int main() {
	scanf("%d %d", &N, &numOfVirus);
	int zeroArea = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &originMap[y][x]);
			if (originMap[y][x] == VIRUS) {
				virusVec.push_back(53 * y + x);
			}
			zeroArea += (originMap[y][x] !=WALL);
		}
	}
	virusLoc = (int)virusVec.size();
	zeroArea -= numOfVirus;
	releaseVirus(0,0, zeroArea);
	answer = (answer == 3000) ? -1 : answer;
	printf("%d\n", answer);
	return 0;
}