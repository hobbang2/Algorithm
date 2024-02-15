#include <iostream>
#include <algorithm>
#include <vector>

int N = 0;
// false : prime, true: not prime
bool isNotPrime[4000001] = { false, };

void getPrimeVec(const int & limitNum, std::vector<int> & primeVec) {

	for (int num = 2; num * num <= limitNum; ++num) {
		if (false == isNotPrime[num]) {
			for (int mulNum = num * num; mulNum <= limitNum; mulNum += num) {
				isNotPrime[mulNum] = true;
			}
		}
	}

	for (int num = 2; num <= limitNum; ++num) {
		if (true == isNotPrime[num]) {
			continue;
		}
		primeVec.emplace_back(num);
	}
	return ;
}


int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> N;
	std::vector <int> primeVec;
	primeVec.reserve(N + 1);
	getPrimeVec(N, primeVec);
	primeVec.emplace_back(0);

	int startIdx = 0, endIdx = 0;
	int primeCnt = static_cast <int> (primeVec.size()) - 1;
	int curSum = primeVec[0];
	int result = 0;

	while ((startIdx <= endIdx) && (endIdx < primeCnt)) {

		// 소수의 조합으로 제안된 숫자를 나타낼 수 있음
		if (curSum == N) {
			++result;
			curSum -= primeVec[startIdx];
			++startIdx;
			++endIdx;
			curSum += primeVec[endIdx];

		}
		// 현재까지의 소수의 합이 제안된 숫자보다 큼
		else if (curSum > N) {
			curSum -= primeVec[startIdx];
			++startIdx;
		}
		// 현재까지의 소수의 합이 제안된 숫자보다 작음
		else if (curSum < N) {
			++endIdx;
			curSum += primeVec[endIdx];
		}
		else {
			// nothing todo ;
		}

	}

	std::cout << result << "\n";

	return 0;
}