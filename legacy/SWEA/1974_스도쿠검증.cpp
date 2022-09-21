#include <cstdio>
#include <vector>

using namespace std;

vector <vector <int> > map(10, vector <int>(10, 0));

bool columnChk() {
	for (int x = 0; x < 9; x++) {
		int sum = 0;
		for (int y = 0; y < 9; y++) {
			sum += map[y][x];
		}
		if (sum != 45) {
			return false;
		}
	}
	return true;
}

bool partialChk() {
	int cnt[3][3] = { 0, };
	for (int x = 0; x < 9; x++) {
		int curX = x / 3;
		for (int y = 0; y < 9; y++) {
			int curY = y / 3;
			cnt[curY][curX] += map[y][x];
		}
	}
	for (int cntY = 0; cntY < 3; cntY++) {
		for (int cntX = 0; cntX < 3; cntX++) {
			if (cnt[cntY][cntX] != 45) {
				return false;
			}
		}
	}
	return true;
}



int main() {
	int T = 0;
	int tc = 0;
	scanf("%d", &T);
	int answer = 0;
	int y = 0, x = 0;
	bool flag = false;
	for (tc = 1; tc <= T; tc++) {
		flag = false;
		for (y = 0; y < 9; y++) {
			int sum = 0;
			for (x = 0; x < 9; x++) {
				scanf("%d", &map[y][x]);
				sum += map[y][x];
			}
			if (sum != 45) {
				flag = true;
			}
		}

		if ((flag == false) && (columnChk() == true) && (partialChk() == true)) {
			answer = 1;
		}
		printf("#%d %d\n", tc, answer);
		answer = 0;
	}
	return 0;
}