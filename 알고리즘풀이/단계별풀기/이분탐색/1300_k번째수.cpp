#include <cstdio>

using namespace std;

void getNumber(int & A, int & B) {
	scanf("%d %d", &A, &B);
	return;
}

int binarySearch(const int & N, const int & K) {
	int start = 1, end = K;
	int mid = 0;
	int ans = 0;
	while (start <= end) {
		mid = (start + end) >> 1;
		int cnt = 0;
		for (int n = 1; n <= N; n++) {
			cnt += (mid/n < N) ? mid/n : N;
		}
		if (cnt < K) {
			start = mid + 1;
		}
		else {
			// 정답 후보들
			ans = mid;
			end = mid -1;
		}
	}
	return ans;
}
int main() {
	int N = 0, K = 0;
	int ans = 0;
	getNumber(N, K);
	ans = binarySearch(N,K);
	printf("%d\n", ans);
	return 0;
}
