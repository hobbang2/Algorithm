#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>

#define pil pair<int,long long>

using namespace std;
int N; // 최대 50만명의 사람
/**
두 사람 A와 B가 서로 볼 수 있으려면 두 사람 사이에 A 또는 B보다 키가 큰 사람이 없어야 함
줄에 서 있는 사람의 키가 주어졌을 때, 서로 볼 수 있는 쌍의 수를 구하는 프로그램
*/

int main() {

	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	cin >> N;
	vector <int> heightVec(N, 0);

	for (int idx = 0; idx < N; ++idx) {
		cin >> heightVec[idx];
	}

	deque <pil> dq; // 서로 마주보는지 확인하기 위한 stack으로 사용: {키, 동일한 키 개수}
	long long result = 0;
	int continuousCnt = 0;

	for (int idx = 0; idx < N; ++idx) {

		const int& curPersonH = heightVec[idx];

		// 현재 확인하는 idx의 사람보다 키가 작으면 다음 사람이 볼 수 없다.
		// 스택에는 현재 idx의 사람보다 키가 크거나 같은 사람만 남게 함 
		while ((false == dq.empty()) && (dq.back().first < curPersonH)) {
			pil curData = dq.back();
			dq.pop_back();
			result += curData.second;
		}

		// 스택이 비어있는 경우 그냥 넣는다.
		if (dq.empty()) {
			dq.push_back(pil{ curPersonH, 1 });
			continue;
		}

		const pil& lastData = dq.back();
		const int lastH = lastData.first;
		const long long lastCnt = lastData.second;

		if (lastH == curPersonH) {
			// 마지막 데이터 빼기 
			dq.pop_back();
			result += lastCnt;

			// stack이 비어있지 않으면 마주볼 수 있는 사람이 있음
			if (false == dq.empty()) {
				result += 1;
			}

			// Count 갱신해서 넣기 
			dq.push_back({ curPersonH, lastCnt + 1 });
		}

		else if (lastH > curPersonH) {
			// 이전 사람과 마주볼 수 있으므로 +1
			result += 1;
			dq.push_back({ curPersonH, 1 });
		}

	}

	cout << result;
}

