#include <cstdio>
// cout  에서 format 지정 출력하는거 검색해보기 
#include <cmath>
#include <set>
#include <map>
#include <vector>

#define E_VALUE 0.0000000001
using namespace std;

int N;
double wholeW;
set <double> answer;
vector <bool> check(11, false);
map<double, double> magnetics;

void cleaner() {
	set <double> empty;
	vector <bool> emptyChk(11, false);
	map<double, double> emptyMap;
	wholeW = 0.0;
	answer.swap(empty);
	check.swap(emptyChk);
	magnetics.swap(emptyMap);
};

void gameStart(int idx, int cnt, int tCnt, vector <double> & vec) {
	if (idx > N-1 || cnt > N-1) {
		return;
	}

	if (cnt >= 1) {
		int fCnt = N - tCnt;
		if (fCnt == 0 || tCnt == 0) {
			return;
		}
		double trueW = 0, falseW = 0;
		double trueD = 0, falseD = 0;
		map <double, double> ::iterator it = magnetics.begin();
		double range[2] = { 0.0, };

		for (int n = 0; n < N; n++) {
			if (check[n] == true) {
				trueD += it->first;
				trueW += it->second;
				if(n == (tCnt-1)){
					range[0] = it->first;
				}
			}
			else if (check[n] == false) {
				falseD += it->first;
				falseW += it->second;
				if (n == (tCnt)) {
					range[1] = it->first;
				}
			}
			it++;
		}

		double target = (range[0]+range[1])/2;
		double tmpAlpha = sqrt(trueW / falseW);
		double alpha[2] = { tmpAlpha,-tmpAlpha };
		for (int a = 0; a < 2; a++) {
			if (((alpha[a] * fCnt + tCnt) == 0) || ((tCnt*target - trueD) == 0) || ((falseD - fCnt * target) == 0)) {
				continue;
			}
			//target = (alpha[a] * falseD - trueD) / (fCnt*alpha[a] - tCnt);
			target = (trueD + alpha[a] * falseD) / (alpha[a]*fCnt+tCnt);
			if ((target <= range[0])|| (target >= range[1])) {
				continue;
			}
			double trueValue = trueW / (pow((tCnt*target - trueD), 2));
			double falseValue = falseW / (pow((falseD-fCnt*target), 2));
			if (abs(trueValue - falseValue) <= E_VALUE) {
				answer.insert(target);
			}
		}
	}

	check[idx] = true;
	gameStart(idx + 1, cnt + 1, tCnt + 1, vec);
}

int main() {
	int T = 0, tc = 1;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) {
		scanf("%d", &N);
		vector <double> tmpVec((N << 1) + 1, 0);
		check.reserve(N + 1);

		for (int n = 0; n < (N << 1); n++) {
			scanf("%lf", &tmpVec[n]);
		}

		for (int n = 0; n < N; n++) {
			double curX = tmpVec[n];
			double curW = tmpVec[N + n];
			wholeW += curW;
			magnetics[curX] = curW;
		}
		gameStart(0, 0, 0, tmpVec);
		printf("#%d ", tc);
		set <int> ::iterator setIt;
		for (auto i : answer) {
			printf("%.10lf ", i);
		}
		printf("\n");
		cleaner();
	}
	return 0;
}