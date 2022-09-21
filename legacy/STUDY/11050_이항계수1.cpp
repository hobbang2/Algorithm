#include <cstdio>
#include <vector>

using namespace std;

unsigned int nCkVec[11][11];

unsigned int nCk(int n, int k) {
	if (k == 0 || k == n) {
		return 1;
	}
	else if (nCkVec[n][k] != 0) {
		return nCkVec[n][k];
	}
	else {
		return nCkVec[n][k] = nCk(n - 1, k - 1) + nCk(n - 1, k);
	}
}

int main() {
	int N = 0, K = 0;	
	scanf("%d %d", &N, &K);
	printf("%u\n", nCk(N, K));
	return 0;
}