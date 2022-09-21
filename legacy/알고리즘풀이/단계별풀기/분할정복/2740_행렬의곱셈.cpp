#include <cstdio>

int A[101][101];
int B[101][101];
int ans[101][101];

int main() {
	int N = 0, M = 0, K = 0;
	scanf("%d %d", &N, &M);
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			scanf("%d", &A[n][m]);
		}
	}
	scanf("%d %d", &M, &K);
	for (int m = 0; m < M; m++) {
		for (int k = 0; k < K; k++) {
			scanf("%d", &B[m][k]);
		}
	}

	for (int n = 0; n < N; n++) {
		for (int k = 0; k < K; k++) {
			int curSum = 0;
			for (int m = 0; m < M; m++) {
				curSum += A[n][m] * B[m][k];
			}
			ans[n][k] = curSum;
		}
	}

	for (int n = 0; n < N; n++) {
		for (int k = 0; k < K; k++) {
			printf("%d ", ans[n][k]);
		}
		printf("\n");
	}
	return 0;
}