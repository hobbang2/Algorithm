#include <cstdio>
#include <queue>
using namespace std;

enum {EMPTY = -1,YET =0 ,WELL = 1,VISITED= 7};
enum {UP = -1, DOWN = 1};
int dirH[6] = { 0,0,0,0,-1,1 };
int dirY[6] = { -1,0,1,0 };
int dirX[6] = { 0,1,0,-1 };

int map[101][101][101] = { 0, };
int M, N, H;
int total = 0;

typedef struct location {
	int h, y, x;
};

queue <location> wellTomato;

bool isInRange(int h, int y, int x) {
	if (h < 0 || h >= H || y < 0 || y >= N || x < 0 || x >= M) {
		return false;
	}
	return true;
}

int infection() {
	int qSize =(int)wellTomato.size();
	int days = 0;
	int nextH = 0, nextY = 0, nextX = 0;
	location curLocation = { 0,0,0 };
	while (wellTomato.empty() == false) {
		if (total == 0) {
			break;
		}
		days += 1;
		qSize = (int)wellTomato.size();
		for (int s = 0; s < qSize; s++) {
			curLocation = wellTomato.front(); wellTomato.pop();
			for (int d = 0; d < 6; d++) {
				nextH = curLocation.h + dirH[d];
				nextY = curLocation.y + dirY[d];
				nextX = curLocation.x + dirX[d];
				if (isInRange(nextH, nextY, nextX) == true && map[nextH][nextY][nextX] != EMPTY) {
					if (map[nextH][nextY][nextX] == YET) {
						total -= 1;
					}
					if (map[nextH][nextY][nextX] != VISITED) {
						map[nextH][nextY][nextX] = VISITED;
						wellTomato.push({ nextH,nextY,nextX });
					}
				}
			}
		}
	}
	return (total == 0)?days : -1;
}


int main() {
	scanf("%d %d %d", &M, &N, &H);

	for (int h = 0; h < H; h++) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				scanf("%d", &map[h][y][x]);
				if (map[h][y][x] == YET) {
					total += 1;
				}
				if (map[h][y][x] == WELL) {
					map[h][y][x] = VISITED;
					wellTomato.push({ h,y,x });
				}
			}
		}
	}

	int days = 0;
	if (total != 0) {
		days = infection();
	}
	printf("%d\n", days);
	return 0;
}