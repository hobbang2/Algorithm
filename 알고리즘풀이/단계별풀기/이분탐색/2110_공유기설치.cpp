#include <cstdio>
int home[200001] = { 0, };
int buf[200001] = { 0, };
int N, C;

void mergeSort(int * p, int len) {
	if (len < 2) return;
	int m = (len >> 1);
	int i = 0, j = m, k = 0;
	mergeSort(p, m);
	mergeSort(p +m, len - m );
	while ((i < m) && (j < len)) {
		if (p[i] <= p[j]) {
			buf[k++] = p[i++];
		}
		else {
			buf[k++] = p[j++];
		}
	}
	while ((i < m)) {
		buf[k++] = p[i++];
	}
	while ((j < len)) {
		buf[k++] = p[j++];
	}
	for (int idx = 0; idx < len; idx++) {
		p[idx] = buf[idx];
	}
}

bool isPossibleDist(int d) {
	int curValue = home[0];
	int cnt = 1;
	for (int n = 1; n < N; n++) {
		if ((home[n] - curValue) >= d) {
			cnt += 1;
			curValue = home[n];
		}
	}
	return (cnt >= C);
}

int main() {
	scanf("%d %d", &N, &C);
	for (int n = 0; n < N; n++) {
		scanf("%d", &home[n]);
	}
	mergeSort(home, N);
	int minimum = 1, maximum = 1000000000;
	int mid = 0;
	while (minimum + 1 < maximum) {
		mid = (minimum + maximum) >> 1;
		if (isPossibleDist(mid) == true) {
			minimum = mid;
		}
		else {
			maximum = mid;
		}
	}
	
	printf("%d", minimum);

	return 0;
}