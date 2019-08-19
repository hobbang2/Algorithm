#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define MAX_VALUE 1000000000
int nCkVec[201][201];

int nCk(int n, int k) {
	if (k == 0 || k == n) {
		return  nCkVec[n][k] = 1;
	}
	else if (nCkVec[n][k] != 0) {
		return nCkVec[n][k];
	}
	else {
		int nextValue = nCk(n - 1, k - 1) + nCk(n - 1, k);
		return nCkVec[n][k] = ((nextValue > MAX_VALUE) ? MAX_VALUE + 1 : nextValue);
	}
}

void getAnswer(int n, int m, int k, int len, string & ans) {
	if (len == 0) {
		return;
	}
	if (nCkVec[n - 1][m - 1] >= k) {
		ans += 'a';
		getAnswer(n - 1, m - 1, k, len - 1, ans);
	}
	else {
		ans += 'z';
		getAnswer(n - 1, m, k - nCkVec[n - 1][m - 1], len - 1, ans);
	}
	return;
}


int main() {
	int K = 0, N = 0, M = 0;
	cin >> N >> M >> K;
	string answer = "";

	for (int y = 0; y <= N + M; y++) {
		nCkVec[y][y] = 1;
		nCkVec[y][0] = 1;
	}

	int maxValue = nCk(N + M, N);
	//for (int y = 0; y <= N + M; y++) {
	//	for (int x = 0; x <= N + M; x++) {
	//		cout << nCkVec[y][x] << " ";
	//	}
	//	cout << "\n";
	//}
	if (maxValue < K) {
		cout << -1 << '\n';
	}
	else {
		getAnswer(N + M, N, K, N + M, answer);
		cout << answer << "\n";
	}

	return 0;
}

