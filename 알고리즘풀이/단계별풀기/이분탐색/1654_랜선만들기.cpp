#include <cstdio>
long long ans = -1;
long long minValue = 2147483647;
long long maxValue = -1;
int K = 0, N = 0;
long long having[10001];

void findMaxValue(long long s, long long e) {
    // mid = s + (e-s+1)/2;
	long long mid = ((s + e) >> 1);
	int tmp = 0;
	if (ans < mid) {	
		for (int idx = 0; idx < K; idx++) {
			if (mid != 0)
				tmp += (having[idx] / mid);
		}
		if (tmp >= N) {
			ans = (ans < mid) ? mid: ans;
			findMaxValue(mid, e+1);
		}
		else {
			findMaxValue(s, mid);
		}
	}
	return;
}
int main() {
	scanf("%d %d", &K, &N);
	for (int k = 0; k < K; k++) {
		scanf("%ld", &having[k]);
		minValue = (having[k] < minValue) ? (having[k]) : (minValue);
		maxValue = (having[k] > maxValue) ? (having[k]) : (maxValue);

	}
	findMaxValue(1, maxValue+1);

	printf("%d\n", ans);
	return 0;
}