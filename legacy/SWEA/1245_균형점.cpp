#include <cstdio>
// cout  에서 format 지정 출력하는거 검색해보기 
#include <cmath>
#include <map>
#include <vector>

#define E_VALUE 0.0000000000001
using namespace std;

int N;
map<int,pair <double, double> > magnetics;

void cleaner() {
	map<int, pair< double, double> > emptyMap;
	magnetics.swap(emptyMap);
};

void gameStart() {
	double begin = 0.0, end = 0.0, target = 0.0;
	for (int orient = 0; orient < N - 1; orient++) {
		int cnt = 0;
		begin = magnetics[orient].first;
		end = magnetics[orient + 1].first;
		for (; cnt < 60; cnt++) {
			target = (begin + end) / 2.0;
			double leftValue = 0.0;
			double rightValue = 0.0;
			for (int left = 0; left <=orient; left++) {
				leftValue += (magnetics[left].second) / pow(magnetics[left].first - target, 2);
			}
			for (int right = orient+1; right <=N - 1; right++) {
				rightValue += (magnetics[right].second) / pow(magnetics[right].first - target, 2);
			}
            // 자석으로부터 떨어질수록 인력이 약하게 작용됨
			if(abs(leftValue - rightValue) < E_VALUE){
                break;
            }
            if (leftValue > rightValue) {
                begin = target;
			}
			else {
				end = target;
            }
		}
		printf("%.10lf ", target);
	}
}

int main() {
	int T = 0, tc = 1;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) {
		scanf("%d", &N);
		vector <double> tmpVec((N << 1) + 1, 0);

		for (int n = 0; n < (N << 1); n++) {
			scanf("%lf", &tmpVec[n]);
		}

		for (int n = 0; n < N; n++) {
			double curX = tmpVec[n];
			double curW = tmpVec[N + n];
			magnetics[n] = make_pair(curX,curW);
		}
		printf("#%d ", tc);
		gameStart();
		printf("\n");
		cleaner();
	}
	return 0;
}