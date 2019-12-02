#include <cstdio>
#include <cassert>
#define MOD 1000

int N = 0;

class matrix {
	int R, C;
	int ** mat;
public:
	matrix(int _R = 6,int _C = 6):R(_R),C(_C) {
		mat = new int*[R]();
		for (int r = 0; r < R; r++) {
			mat[r] = new int[C]();
		}
	}

	matrix(const matrix & m) {
		R = m.R;
		C = m.C;
		mat = new int*[R]();
		for (int r = 0; r < R; r++) {
			mat[r] = new int[C]();
		}
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				mat[r][c] = m.mat[r][c];
			}
		}
	}

	void getMat(int N) {
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				scanf("%d", &mat[r][c]);
				mat[r][c] %= MOD;
			}
		}
	}

	matrix & operator=(const matrix & m) {
		if (this != &m) {
			delete[] mat;
			R = m.R, C = m.C;
			mat = new int*[R]();
			for (int r = 0; r < R; r++) {
				mat[r] = new int[C]();
			}

			for (int r = 0; r < R; r++) {
				for (int c = 0; c < C; c++) {
					mat[r][c] = m.mat[r][c];
				}
			}
		}
		return *this;
	}

	matrix operator*(const matrix & tar) {
		assert(C == tar.R);
		matrix matR;
		for (int n = 0; n < R; n++) {
			for (int k = 0; k < tar.C; k++) {
				int curSum = 0;
				for (int m = 0; m < C; m++) {
					curSum += (mat[n][m] * tar.mat[m][k]) % MOD;
				}
				matR.mat[n][k] = curSum % MOD;
			}
		}
		return matR;
	}

	void printMat() {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				printf("%d ", mat[y][x]);
			}
			printf("\n");
		}
	}

	~matrix() {
		for (int n = 0; n < 6; n++) {
			delete[] mat[n];
		}
		delete[] mat;
	}


};

matrix calMat(matrix matA,matrix matB){
	matrix matR;
	matR = matA * matB;
	return matR;
}

matrix calPow(matrix target,long long numOfPow){
	if (numOfPow == 1) {
		return target;
	}

	matrix tmpMat;
	tmpMat = calPow(target,numOfPow/2);
	if (numOfPow % 2 == 0) {
		return calMat(tmpMat, tmpMat);
	}
	else {
		return calMat(calMat(tmpMat, tmpMat), target);
	}
}


int main() {
	long long B = 0;
	
	scanf("%d %lld", &N, &B);
	matrix A;
	A.getMat(N);
	matrix ans=calPow(A, B);
	ans.printMat();
	return 0;
}
