#include <iostream>

// scoreTalbe[0][0] : 0 번째 index 칸의 점수
// scoreTalbe[0][1] : 0 번째 index 칸에서 한 칸 이동했을 때 index 
// scoreTalbe[0][5] : 0 번째 index 칸에서 다섯 칸 이동했을 때 index 
const int socreTable[33][6] = {
	{0, 1, 2, 3, 4, 5},
	{2, 2, 3, 4, 5, 6},
	{4, 3, 4, 5, 6, 7},
	{6, 4, 5, 6, 7, 8},
	{8, 5, 6, 7, 8, 9},
	{10, 21, 22, 23, 24, 30},
	{12, 7, 8, 9, 10, 11},
	{14, 8, 9, 10, 11, 12},
	{16, 9, 10, 11, 12, 13},
	{18, 10, 11, 12, 13, 14},
	{20, 28, 29, 24, 30, 31},
	{22, 12, 13, 14, 15, 16},
	{24, 13, 14, 15, 16, 17},
	{26, 14, 15, 16, 17, 18},
	{28, 15, 16, 17, 18, 19},
	{30, 27, 26, 25, 24, 30},
	{32, 17, 18, 19, 32, -1}, // 골인 
	{34, 18, 19, 32, -1, -1}, // 골인 
	{36, 19, 32, -1, -1, -1}, // 골인 
	{38, 32, -1, -1, -1, -1}, // 골인 
	{0, 0, 0, 0, 0, 0 }, // 공석 index 20
	{13, 22, 23, 24, 30, 31},
	{16, 23, 24, 30, 31, 32}, // 골인
	{19, 24, 30, 31, 32, -1}, // 골인
	{25, 30, 31, 32, -1, -1}, // 골인
	{26, 24, 30, 31, 32, -1}, // 골인
	{27, 25, 24, 30, 31, 32}, // 골인
	{28, 26, 25, 24, 30, 31},
	{22, 29, 24, 30, 31, 32}, // 골인
	{24, 24, 30, 31, 32, -1}, // 골인
	{30, 31, 32, -1, -1, -1}, // 골인
	{35, 32, -1, -1, -1, -1}, // 골인
	{40, -1, -1, -1, -1, -1}, // 골인
};

int horse[5] = { 0, };
int horseLocation[33] = { 0, };
int diceNum[10] = { 0, };
int result = 0;

void game(int curIdx, int score, int cnt) {
	result = (result < score) ? score : result;

	if (cnt >= 10) {
		return; 
	}

	// 말 index : 0, 1, 2, 3 
	if ( curIdx > 4) {
		return; 
	}

	for (int idx = 1; idx <= 4; idx++) {
		
		// 이미 결승선 들어옴 
		if (-1 == horse[idx]) {
			continue;
		}

		const int curPosition = horse[idx];
		const int movement = diceNum[cnt];
		const int nextPosition = socreTable[curPosition][movement]; 
		
		horse[idx] = nextPosition;

		if (-1 == nextPosition) {
			horseLocation[curPosition] = 0;
			game(idx, score, cnt + 1);
			horseLocation[curPosition] = idx;
		}

		else if (0 == horseLocation[nextPosition]) {
			horseLocation[curPosition] = 0;
			horseLocation[nextPosition] = idx;
			game(idx, score + socreTable[nextPosition][0], cnt + 1);
			horseLocation[curPosition] = idx;
			horseLocation[nextPosition] = 0;

		}
		horse[idx] = curPosition;
	}

	return; 
}

int main() {

	for (int idx = 0; idx < 10; ++idx) {
		std::cin >> diceNum[idx];
	}

	for (int idx = 1; idx <= 4; ++idx) {
		game(idx, 0, 0);
	}

	std::cout << result; 

	return 0;
}