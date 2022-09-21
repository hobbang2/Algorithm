#include <cstdio>
#include <vector>

using namespace std;

unsigned int nCkVec[1001][1001];

unsigned int nCk(int n, int k) {
	if (k == 0 || k == n) {
		return  nCkVec[n][k] = 1;
	}
	else if (nCkVec[n][k] != 0) {
		return nCkVec[n][k];
	}
	else {
		return nCkVec[n][k] = nCk(n - 1, k - 1) + nCk(n - 1, k);
	}
}

int main() {
	int T = 0,N = 0, M = 0;
	int answer = 0;
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++) {
		scanf("%d %d", &N, &M);
		printf("%u\n", nCk(M, N));
	}
	return 0;
}