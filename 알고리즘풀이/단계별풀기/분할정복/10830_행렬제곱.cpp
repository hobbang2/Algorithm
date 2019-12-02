#include <cstdio>

#define MOD 1000

int N = 0;
long long B = 0;
int ** A;

// 2차원 배열 리턴 
int (** calMat(int ** matA,int ** matB)){
	int ** matR = new int* [6];
	for (int r = 0; r < 6; r++) {
		matR[r] = new int[6];
	}

	for (int n = 0; n < N; n++) {
		for (int k = 0; k < N; k++) {
			int curSum = 0;
			for (int m = 0; m < N; m++) {
				curSum += (matA[n][m] * matB[m][k])%MOD;
			}
			matR[n][k] = curSum % MOD;
		}
	}
	return matR;
}

int (** calPow(int ** target,long long numOfPow)){
	if (numOfPow == 1) {
		return target;
	}
	int **tmpMat = calPow(target,numOfPow/2);
	if (numOfPow % 2 == 0) {
		return calMat(tmpMat, tmpMat);
	}
	else {
		return calMat(calMat(tmpMat, tmpMat), target);
	}
}

void printMat(int ** mat) {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			printf("%d ", mat[y][x]);
		}
		printf("\n");
	}
}

int main() {
	
	scanf("%d %lld", &N, &B);

	A = new int *[6];
	for (int a = 0; a < 6; a++) {
		A[a] = new int[6];
	}

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < N; m++) {
			scanf("%d", &A[n][m]);
			A[n][m] %= MOD;
		}
	}
	int ** ans=calPow(A, B);
	printMat(ans);
	return 0;
}
