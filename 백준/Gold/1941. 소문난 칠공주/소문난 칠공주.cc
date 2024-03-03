#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
const int N = 5; 
vector <string> seatMap;

// 북, 남, 서, 동
int dr[4] = {-1, 1, 0, 0 };
int dc[4] = {0, 0, -1, 1};
int result = 0;

bool isInMap(const int & r, const int & c) {

	if (r < 0 || c < 0) {
		return false;
	}

	if (r >= N || c >= N) {
		return false;
	}

	return true;
}

// getSeatComb에서 채워지는 값, 25C7의 결과
bool coordVisited[25] = { false, };

// 고른 7칸이 인접한지 확인하기
bool isConnect(int startCoord) {

	int cnt = 0;
	bool visited[25] = { false, };

	queue <int> coordQ;

	coordQ.push(startCoord);
	visited[startCoord] = true;

	while (false == coordQ.empty()) {
		
		int curCoord = coordQ.front(); coordQ.pop();
		int curR = curCoord / N; int curC = curCoord % N;
		// 지나온 칸의 개수를 세아리자. 7칸이 되면 연결 여부를 모두 확인한 것임
		cnt += 1;

		if (cnt == 7) {
			return true;
		}
		
		for (int dIdx = 0; dIdx < 4; ++dIdx) {
			int nextR = curR + dr[dIdx];
			int nextC = curC + dc[dIdx];

			int nextCoord = nextR * 5 + nextC;

			// 맵 범위를 벗어나는지 확인
			if (false == isInMap(nextR, nextC)) {
				continue; 
			}

			// 257C에서 골라진 칸인지 확인
			if (false == coordVisited[nextCoord]) {
				continue;
			}

			// 방문 여부 확인
			if (true == visited[nextCoord]) {
				continue; 
			}

			visited[nextCoord] = true;
			coordQ.push(nextCoord);
		}
	}

	return false;
}

void getAnswer(int curIdx , int seatedCnt, int dasom) {

	if (7 == seatedCnt) {
		// 7칸 중에 4명이 다솜파이고 7칸이 서로 인접해 있으면 +1

		if ((dasom >= 4)&&(true == isConnect(curIdx))) {
			result += 1;
		}
		return;
	}

	// 25개의 칸 중에 7개를 골라보자
	for (int idx = curIdx ; idx <25; ++idx) {

		if (coordVisited[idx]) {
			continue;
		}

		coordVisited[idx] = true;
		int curR = idx / N;
		int curC = idx % N;
		int isDasom = ('S' == seatMap[curR][curC]) ? 1 : 0;
		getAnswer(idx, seatedCnt + 1, dasom + isDasom);
		coordVisited[idx] = false;
	}

}


int main() {

	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	for (int r = 0; r < N; ++r) {
		string curLine;
		cin >> curLine;
		seatMap.emplace_back(curLine);
	}


	getAnswer(0, 0, 0);

	cout << result;

	return 0;

}