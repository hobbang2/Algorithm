#include <cstdio>
#include <vector>

using namespace std;

double nCkVec[2501][2501];

double nCk(int n, int k) {
	if (k == 0 || k == n) {
		return nCkVec[n][k] = 1;
	}
	else if (nCkVec[n][k] != 0) {
		return nCkVec[n][k];
	}
	else {
		return nCkVec[n][k] = nCk(n - 1, k - 1) + nCk(n - 1, k);
	}
}

int main() {
	int M = 0, K = 0;
	int total = 0;
	int rock = 0;
	double mother = 0;
	double son = 0;

	vector <int> rocks;
	scanf("%d", &M);


	for (int m = 0; m < M; m++) {
		scanf("%d", &rock);
		rocks.push_back(rock);
		total += rock;
	}

	scanf("%d", &K);

	for (int idx = 0; idx <= total; idx++) {
		nCkVec[idx][idx] = 1;
		nCkVec[idx][0] = 1;
	}


	mother = nCk(total, K);

	for (int idx = 0; idx < (int)rocks.size(); idx++) {
		son += nCkVec[rocks[idx]][K];
	}

	printf("%.16lf\n",son/mother);
	return 0;
}