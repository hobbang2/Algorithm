#include <cstdio>
#include <iostream>
#include <vector>

#define MAX_HORES  4 + 1  
#define MAX_TURN 1000

enum {
	DIR_RIGHT = 1, 
	DIR_LEFT , 
	DIR_UP, 
	DIR_DOWN  
};

enum {
	WHITE = 0,
	RED,
	BLUE,
};


int dr[5] = { 0, 0, 0, -1 , 1 };
int dc[5] = { 0, 1, -1, 0, 0 };

typedef struct Horse {
	int dir = 0; 
	int curR = 0; 
	int curC = 0;
};


// 말의 index 를 저장할 map
std::vector<int> chess[13][13];
Horse horseArr[11] = { {0,0,0} };
int N, K = 0;

void clearMap() {
	for (int r = 1; r <= N; ++r) {
		for (int c = 1; c <= N; ++c) {
			// 0: 색깔, 1: 현재 칸 말 수
			chess[r][c].resize(12);
		}
	}
	return; 
}

void changeDir(Horse& targetH) {

	if (targetH.dir == DIR_RIGHT) targetH.dir = DIR_LEFT;
	else if (targetH.dir == DIR_LEFT) targetH.dir = DIR_RIGHT;
	else if (targetH.dir == DIR_UP) targetH.dir = DIR_DOWN;
	else if (targetH.dir == DIR_DOWN) targetH.dir = DIR_UP;

	return;
}

int main() {
	
	std::cin >> N >> K;

	clearMap();
	
	for (int r = 1; r <= N; ++r) {
		for (int c = 1; c <= N; ++c) {
			int curColor = 0;
			std::cin >> curColor;
			chess[r][c][0] = (curColor);
		}
	}

	for (int horseIdx = 1; horseIdx <= K; ++horseIdx) {

		std::cin >> horseArr[horseIdx].curR >> horseArr[horseIdx].curC >> horseArr[horseIdx].dir;
		const int& curR = horseArr[horseIdx].curR;
		const int& curC = horseArr[horseIdx].curC;

		int curIdx= ++chess[curR][curC][1] + 1 ;
		chess[curR][curC][curIdx] = (horseIdx);
	}
	
	int result = 0;
	bool bStopGame = false; 

	while (true) {
		++result;

		for (int idx = 1; idx <= K; ++idx) {
			
			Horse& target = horseArr[idx];
			int curR = target.curR; 
			int curC = target.curC; 
			int nextR = target.curR + dr[target.dir];
			int nextC = target.curC + dc[target.dir];
			bool bAlreadyChangeDir = false;

			if ((nextR <= 0 || nextC <= 0) || (nextR > N || nextC > N)|| chess[nextR][nextC][0] == BLUE) {
				
				changeDir(target);
				nextR = target.curR + dr[target.dir];
				nextC = target.curC + dc[target.dir];
				bAlreadyChangeDir = true; 
			}

			// 파란색 타일을 마주하고 반대 방향으로 갔을 때 다시 벽인 경우
			// - 방향 변경 없이 다음 말 이동
			if ((nextR <= 0 || nextC <= 0) || (nextR > N || nextC > N)|| chess[nextR][nextC][0] == BLUE) {
				continue; 
			}

			int curColor = chess[nextR][nextC][0];

			int numOfHorse = static_cast <int> (chess[curR][curC][1]);
			int curHorseLoc = 0;

			// vector의 맨 앞 두 칸은 각각 맵의 색깔과 말의 개수
			for (int h = 2; h <= numOfHorse + 1; ++h) {
				if (idx == chess[curR][curC][h]) {
					curHorseLoc = h; 
					break;
				}
			}

			switch (curColor) {
			case WHITE : 
				// 해당 말 위에 있는 말까지 전부 같은 방향으로 움직인다. 
				for (int moveIdx = curHorseLoc; moveIdx <= numOfHorse + 1; ++moveIdx) {
					if (0 == chess[curR][curC][moveIdx]) {
						std::cout << "[ERROR] " << "WHITE Case Error" << std::endl;
						break;
					}

					int targetHorseIdx = chess[curR][curC][moveIdx];
					chess[nextR][nextC][1] += 1;
					int nextHorseNum = chess[nextR][nextC][1];
					chess[nextR][nextC][nextHorseNum + 1] = (targetHorseIdx);
					chess[curR][curC][moveIdx] = 0;
					chess[curR][curC][1] -= 1;

					horseArr[targetHorseIdx].curR = nextR;
					horseArr[targetHorseIdx].curC = nextC;

					bStopGame |= (4 <= chess[nextR][nextC][1]);
				}
				
				break;
			case RED :

				for (int moveIdx = numOfHorse + 1; moveIdx >= curHorseLoc; --moveIdx) {
					if (0 == chess[curR][curC][moveIdx]) {
						std::cout << "[ERROR] " << "RED Case Error" << std::endl;
						break;
					}

					int targetHorseIdx = chess[curR][curC][moveIdx];
					chess[nextR][nextC][1] += 1;
					int nextHorseNum = chess[nextR][nextC][1];
					chess[nextR][nextC][nextHorseNum + 1] = (targetHorseIdx);
					chess[curR][curC][moveIdx] = 0;
					chess[curR][curC][1] -= 1;

					horseArr[targetHorseIdx].curR = nextR;
					horseArr[targetHorseIdx].curC = nextC;

					bStopGame |= (4 <= chess[nextR][nextC][1]);
				}
				// 해당 말 위에 있는 말부터 역순으로 움직인다. 
				break;
			case BLUE : 
				// 반대 방향으로 바꾸고 한 칸 간다. : 윗쪽 if 문에서 처리 
				// 바꾼 후에 이동하려는 칸이 파란색이면 이동하지 않고 가만히 있는다. 
				//target.curR = nextR;
				//target.curC = nextC;
				break;
			default:
				// nothing to do 
				break;
			}
		}

		if (MAX_TURN < result) {
			result = -1;
			break;
		}

		if (bStopGame) {
			break;
		}
	}

	std::cout << result; 
	return 0;
}

