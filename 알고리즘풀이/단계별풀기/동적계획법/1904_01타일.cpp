#include <cstdio>

#define MOD 15746

int binarySeq(int N) {
	int fValue = 1;
	int sValue = 2;
	if (N == 1) {
		return fValue;
	}
	if (N == 2) {
		return sValue;
	}
	int nextValue = 0;
	for (int n = 3; n <= N; n++) {
		nextValue = ((fValue % MOD) + (sValue % MOD))%MOD;
		fValue = sValue % MOD;
		sValue = nextValue % MOD;
	}
	return sValue;
}



int main() {
	int N = 0;
	scanf("%d", &N);
	int ans = binarySeq(N);
	printf("%d\n", ans);
	
	return 0;
}