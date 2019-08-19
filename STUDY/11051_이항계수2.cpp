#include <cstdio>
#include <vector>

using namespace std;

unsigned int nCkVec[1001][1001];

unsigned int nCkMod(int n, int k,int mod) {
	if (k == 0 || k == n) {
		return 1;
	}
	else if (nCkVec[n][k] != 0) {
		return nCkVec[n][k];
	}
	else {
		return nCkVec[n][k] = (nCkMod(n - 1, k - 1,mod) + nCkMod(n - 1, k,mod))%mod;
	}
}

int main() {
	int N = 0, K = 0;
	int mod = 10007;
	scanf("%d %d", &N, &K);
	printf("%u\n", nCkMod(N, K,mod));
	return 0;
}