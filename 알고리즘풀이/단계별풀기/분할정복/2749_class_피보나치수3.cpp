#include <cstdio>
#include <cassert>
#define MOD 1000000

typedef long long ll;
long long N = 0;

template <typename T>
class matrix {
	int R, C;
	long long ** mat;
public:
	matrix(int _R = 6,int _C = 6):R(_R),C(_C) {
		mat = new T*[R]();
		for (int r = 0; r < R; r++) {
			mat[r] = new T[C]();
		}
	}
	matrix(const T tar[][2],int _R,int _C) {
		R = _R, C = _C;
		mat = new T*[R]();
		for (int r = 0; r < R; r++) {
			mat[r] = new T[C]();
		}
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				mat[r][c] = tar[r][c];
			}
		}
	}
	matrix(const matrix & m) {
		R = m.R;
		C = m.C;
		mat = new T*[R]();
		for (int r = 0; r < R; r++) {
			mat[r] = new T[C]();
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
			for (int n = 0; n < R; n++) {
				delete[] mat[n];
			}
			delete[] mat;

			R = m.R, C = m.C;
			mat = new T*[R]();
			for (int r = 0; r < R; r++) {
				mat[r] = new T[C]();
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
		matrix matR(R,tar.C);
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
		for (int y = 0; y < R; y++) {
			for (int x = 0; x < C; x++) {
				printf("%lld ", mat[y][x]);
			}
			printf("\n");
		}
	}

	void printAns() {
		printf("%lld\n", mat[0][1]);
	}
	~matrix() {
		for (int n = 0; n < R; n++) {
			delete[] mat[n];
		}
		delete[] mat;
	}


};

matrix<ll> calMat(matrix <ll> matA,matrix <ll> matB){
	matrix <ll> matR;
	matR = matA * matB;
	return matR;
}

matrix <ll> calPow(matrix <ll> target,long long numOfPow){
	if (numOfPow == 1) {
		return target;
	}

	matrix <ll> tmpMat(2,2);
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
	long long initial[1][2] = { {0, 1} };
	long long  mult[2][2] = { {0,1},{1,1} };
	matrix <ll> initMat(initial, 1, 2);
	matrix <ll> multMat(mult, 2, 2);

	scanf("%lld", &N);
	matrix <ll> ans = initMat * calPow(multMat, N - 1);
	ans.printAns();
	return 0;
}
