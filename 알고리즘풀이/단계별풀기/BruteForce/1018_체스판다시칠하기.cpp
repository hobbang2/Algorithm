#include <cstdio>
#include <cstring>
// 동, 남 
int dirY[2] = { 0,1 };
int dirX[2] = { 1,0 };
int N, M;
int result = 2700;
char map[55][55];

void gameStart(int _y, int _x,char cpyMap[][55],bool flag) {
	int tmpResult = (flag == true?1:0);
	for (int y = _y; y < _y + 8; y++) {
		for (int x = _x; x < _x + 8; x++) {
			for (int d = 0; d < 2; d++) {
				int nextY = y + dirY[d];
				int nextX = x + dirX[d];
				if (nextY < _y + 8 && nextX < _x + 8 && nextY >= 1 && nextX >= 1) {
					if (cpyMap[y][x] == cpyMap[nextY][nextX]) {
						cpyMap[nextY][nextX] = (cpyMap[nextY][nextX] == 'W' ? 'B' : 'W');
						tmpResult += 1;
					}
				}
			}
		}
	}
	result = (result > tmpResult) ? tmpResult : result;
	return;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int y = 1; y <= N; y++) {
		scanf("%s", map[y]+1);
	}

	for (int y = 1; y <= N - 8 + 1; y++) {
		for (int x = 1; x <= M - 8 + 1; x++) {
			char cpyMap[55][55] = { '0', };
			memcpy(cpyMap, map, sizeof(map));
			gameStart(y,x,cpyMap,false);
			memcpy(cpyMap, map, sizeof(map));
			cpyMap[y][x] = (cpyMap[y][x] == 'W' ? 'B' : 'W');
			gameStart(y, x, cpyMap,true);
		}

	}
	printf("%d\n", result);
	return 0;
}