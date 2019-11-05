#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


int sdoku[11][11] = { false, };
vector <int> likelihoodNum;
vector <int> spaces;
bool colCheck[10][10] = { false, };
bool rowCheck[10][10] = { false, };
bool squareCheck[10][10] = { false, };

void backTracking(int idx, int maxIdx) {
	if (idx == maxIdx) {
		for (int y = 0; y < 9; y++) {
			for (int x = 0; x < 9; x++) {
				printf("%d ", sdoku[y][x]);
			}
			printf("\n");
		}
		exit(0);
	}
	else {
		for (int n = 1; n <= 9; n++) {
			int tmp = spaces[idx];
			int y = tmp / 9, x = tmp % 9;
			if (colCheck[y][n] && rowCheck[x][n] && squareCheck[y / 3 * 3 + x / 3][n]) {
				continue;
			}
			colCheck[y][n] = rowCheck[x][n] = squareCheck[y / 3 * 3 + x / 3][n] = true;
			sdoku[y][x] = n;
			backTracking(idx + 1, maxIdx);
			colCheck[y][n] = rowCheck[x][n] = squareCheck[y / 3 * 3 + x / 3][n] = false;
			sdoku[y][x] = 0;
		}
	}
}

int main() {
	for (int y = 0; y < 9; y++) {
		bool check[10] = { false, };
		int _sum = 0;
		int cnt = 0;
		for (int x = 0; x < 9; x++) {
			scanf("%d", &sdoku[y][x]);
			_sum += sdoku[y][x];
			check[sdoku[y][x]] = colCheck[y][sdoku[y][x]] = rowCheck[x][sdoku[y][x]] = squareCheck[y / 3 * 3 + x / 3][sdoku[y][x]] = true;
			if (sdoku[y][x] == 0) {
				cnt += 1;
				spaces.push_back(y * 9 + x);
			}
		}
		if (cnt == 1) {
			int tmp = spaces.back();
			int _y = tmp / 9;
			int _x = tmp % 9;
			sdoku[_y][_x] = 45 - _sum;
			check[sdoku[_y][_x]] = colCheck[_y][sdoku[_y][_x]] = rowCheck[_x][sdoku[_y][_x]] = squareCheck[_y / 3 * 3 + _x / 3][sdoku[_y][_x]] = true;
			spaces.pop_back();
		}
	}
		int maxIdx = (int)spaces.size();
		backTracking(0, maxIdx);


	return 0;
}