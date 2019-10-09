// swea 최빈수출력 1204
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>

#define pii pair<int,int>

using namespace std;

void cleanVec(vector <int> & target) {
	vector <int> emp(101, 0);
	target.swap(emp);
	return;
}

void getScore(vector <int> & target) {
	int curScore = 0;
	for (int idx = 1; idx <= 1000; idx++) {
		scanf("%d", &curScore);
		target[curScore] += 1;
	}
	return;
}

void intoPq(vector <int> & s,priority_queue <pii, vector <pii> > & pq) {
	pii curPair(0, 0);
	int idx = 0;
	for (idx = 1; idx <=100; idx++) {
		curPair = make_pair(s[idx], idx);
		pq.push(curPair);
	}
	return;
}

int main() {
	int T = 0;
	int tc = 0;
	int answer = 0;
	vector <int> score(101, 0);
    scanf("%d",&T);
	while (T--) {
		priority_queue <pii, vector <pii> > pq;
		answer = 0;
		scanf("%d", &tc);
		getScore(score);
		intoPq(score,pq);
		printf("#%d %d\n", tc, pq.top().second);
		cleanVec(score);
	}
	return 0;
}