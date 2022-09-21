#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

//서 동 남
int dirY[3] = { 0,0,1 };
int dirX[3] = { -1,1,0 };
int map[101][101];
int chk[101][101];

bool isInMap(int y, int x) {
	if (y <=0 || x <= 0 || y > 100 || x > 100) {
		return false;
	}
	return true;
}

int startTarget(int y, int x) {
	while (y >= 1) {
		y -= 1;
		if (map[y][x - 1] == 1) {
            while(map[y][x - 1] == 1){
                x -= 1;
            }
		}
		else if (map[y][x + 1] == 1) {
			while (map[y][x + 1] == 1){
                x+=1;
			}
        }
	}
	return x - 1;
}

int gameStart() {
	int nextY = 0;
	int nextX = 0;
	int y = 1;
	int x = 1;
	int d = 0;
	for (int _x = 1; _x <= 100; _x++) {
		x = _x;
		if (map[y][x] == 0) {
			continue;
		}
		else {
			memset(chk, 0, sizeof(chk));
			while (y < 100)
			{
				chk[y][x] = true;
				for (d = 0; d < 3; d++) {
					nextY = y + dirY[d];
					nextX = x + dirX[d];
					if ((isInMap(nextY, nextX) == true) && (chk[nextY][nextX] == false)&&(map[nextY][nextX]==1)) {
						chk[nextY][nextX] = true;
						y = nextY;
						x = nextX;
						break;
					}
				}
			}
			if (map[y][x] == 2) {
				return _x;
			}
		}
	}
}


int main() {
	int T = 10;
	int t = 1;
	int tc = 0;
	int answer = 0;
	int targetY = 0, targetX = 0;
	for (t = 1; t <= T; t++) {
		scanf("%d", &tc);
		for (int y = 1; y <= 100; y++) {
			for (int x = 1; x <= 100; x++) {
				scanf("%d", &map[y][x]);
				if (map[y][x] == 2) {
					targetY = y, targetX = x;
				}
			}
		}
		answer = startTarget(targetY,targetX);
		printf("#%d %d\n", tc, answer);

	}
	return 0;
}