#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int map[51][51];

int getBenefit(const int & n) {
	int orient = n >> 1;
	int curSpace = 1;
	int incSpace = 2;
	int incX = -1;
	int benefit = 0;
	int y = 0, x = orient;
	int limit = 0;
	for (y = 0; y < n; y++) {
		if (y == orient) {
			incSpace = -2;
			incX = 1;
		}
		limit = x + curSpace;
		for (int cpyX = x ;cpyX < limit; cpyX++) {
			benefit += map[y][cpyX];
		}
		x += incX;
		curSpace += incSpace;
	}
	return benefit;
}


int main() {
	int T = 0;
	int tc = 0;
	int answer = 0;
	scanf("%d", &T);
	int y = 0, x = 0;
	int mapSize = 0;

	for (tc = 1; tc <= T; tc++) {
		scanf("%d", &mapSize);
		for (y = 0; y < mapSize; y++) {
			for (x = 0; x < mapSize; x++) {
				scanf("%1d", &map[y][x]);
			}
		}
		answer = getBenefit(mapSize);
		printf("#%d %d\n", tc, answer);
		memset(map, 0, sizeof(map));
	}
	return 0;
}