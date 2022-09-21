/*https://dyndy.tistory.com/173*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n = 0;
	scanf("%d", &n);
	int triangle[501][501] = { 0, };
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= y; x++) {
			scanf("%d", &triangle[y][x]);
		}
	}

	for (int y = n; y >= 1; y--) {
		for (int x = 1; x <= y; x++) {
			triangle[y - 1][x] += max(triangle[y][x], triangle[y][x + 1]);
		}
	}

	printf("%d\n", triangle[1][1]);


	return 0;
}