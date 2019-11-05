#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


int sdoku[11][11] = { false, };
vector <int> likelihoodNum;
vector <int> spaces;

bool squareCheck() {
	for (int x = 0; x < 9; x += 3) {
		for (int y = 0; y < 9; y += 3) {
			int _sum = 0;
			for (int _y = y; _y < y + 3; _y++) {
				for (int _x = x; _x < x + 3; _x++) {
					_sum += sdoku[_y][_x];
				}
			}
			if (_sum != 45) {
				return false;
			}
		}
	}
	return true;
}

bool columnCheck() {
	for (int y = 0; y < 9; y++) {
		int _sum = 0;
		for(int x= 0; x < 9; x++){
			_sum += sdoku[y][x];
		}
		if (_sum != 45) {
			return false;
		}
	}
	return true;
}

bool rowCheck() {
	for (int x = 0; x < 9; x++) {
		int _sum = 0;
		for (int y = 0; y < 9; y++) {
			_sum += sdoku[y][x];
		}
		if (_sum != 45) {
			return false;
		}
	}
	return true;
}


int main() {
	for (int y = 0; y < 9; y++) {
		bool check[10] = { false, };
		int _sum = 0;
		int cnt = 0;
		for (int x = 0; x < 9; x++) {
			scanf("%d", &sdoku[y][x]);
			_sum += sdoku[y][x];
			check[sdoku[y][x]] = true;
			if (sdoku[y][x] == 0) {
				cnt += 1;
				spaces.push_back(y * 9 + x);
			}
		}
		if (cnt == 1) {
			int tmp = spaces.back();
			sdoku[tmp / 9][tmp % 9] = 45 - _sum;
			spaces.pop_back();
		}
		else {
			for (int c = 1; c < 10; c++) {
				if (check[c] == false) {
					likelihoodNum.push_back(c);
				}
			}
		}
	}
	sort(likelihoodNum.begin(), likelihoodNum.end());
	do {
;		for (int s = 0; s < (int)spaces.size(); s++) {
			sdoku[spaces[s] / 9][spaces[s] % 9] = likelihoodNum[s];
		}
		if (squareCheck() && columnCheck() && rowCheck()) {
			break;
		}
	} while (next_permutation(likelihoodNum.begin(), likelihoodNum.end()));


	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			printf("%d ", sdoku[y][x]);
		}
		printf("\n");
	}


	return 0;
}