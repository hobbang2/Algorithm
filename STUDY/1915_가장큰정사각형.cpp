#include <cstdio>
#include <vector>
#include <algorithm>

#define MIN(a,b,c) (a)>(b)?((b)>(c)?(c):(b)):((a)>(c)?(c):(a))

using namespace std;

int map[1001][1001];

int main() {
	int n = 0, m = 0;
	int answer = 0;
	printf("%d\n\n", MIN(7, 2, 3));

	scanf("%d %d", &n, &m);
	
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			scanf("%1d", &map[y][x]);
		}
	}


	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			if (map[y][x] != 0) {
				map[y][x] += MIN(map[y - 1][x], map[y][x - 1], map[y - 1][x - 1]);
				answer = max(answer, map[y][x]);
			}
		}
	}
	printf("%d\n", answer*answer);

	return 0;
}