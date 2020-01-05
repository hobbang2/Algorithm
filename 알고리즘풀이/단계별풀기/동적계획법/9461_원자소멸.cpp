#include <cstdio>

long long seq[101] = { 0,1,1,1,2,2,0, };

int main() {
	int T = 0;
	int N = 0;
	long long ans = 0;
	scanf("%d", &T);

	int lastValue = 6; 
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &N);
		if (seq[N] != 0) {
			ans = seq[N];
		}
		else {
			for (int l = lastValue; l <= N; l++) {
				seq[l] = seq[l - 1] + seq[l - 5];
			}
			lastValue = N;
			ans = seq[N];
		}
		printf("%lld\n", ans);
	}
	return 0;
}