#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int map[101][101];

int main() {
	int w = 0, h = 0;
	scanf("%d %d", &w, &h);
	for (int y = 1; y <= h; y++) {
		map[y][1] = 1;
	}

	for (int x = 1; x <= w; x++) {
		map[1][x] = 1;
	}

	map[1][1] = 0;

	for (int y = 2; y <= h; y++) {
		for (int x = 2; x <= w; x++) 
		{
			int leftX = (x - 3) > 0 ? (x - 3) : (1);
			int leftY = (y - 3) > 0 ? (y - 3) : (1);

			map[y][x] = (max(map[y][leftX] + map[y - 1][x], map[y][x - 1] + map[leftY][x]))%1000000;
		}
	}

	printf("%d\n", (map[h][w]));

	return 0;
}