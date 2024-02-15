#include <iostream>
#include <algorithm>
#include <vector>

int N, M = 0;

int main() {

	std::cin >> N >> M;
	std::vector<int> sequence(N + 1, 0);

	for (int idx = 0; idx < N; ++idx) {
		std::cin >> sequence[idx];
	}
	
	std::sort(sequence.begin(), sequence.begin() + N);

	int startIdx = 0; int endIdx = 1;
	int result = 2000000003;

	while ((startIdx < endIdx) && (endIdx < N)) {
		int diff = sequence[endIdx] - sequence[startIdx];

		// 차이가 M과 같거나 M보다 크면 startIdx를 옮긴다.
		// 정렬되어 있으므로 startIdx를 옮기면 차이가 더 작아짐
		if (diff >= M) {
			startIdx += 1;
			result = result > diff ? diff : result ;
		}
		// 차이가 M보다 작으면 endIdx를 옮겨서 차이를 더 크게 만들어줌
		else {
			endIdx += 1;
		}
		// start와 end가 같아지면 end를 한 칸 옮겨줌
		if (startIdx == endIdx) {
			endIdx += 1;
		}
	}

	std::cout << result << "\n";


	return 0;
}