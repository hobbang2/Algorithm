#include <cstdio>
#include <vector>
#include <utility>
#include <queue>

#define pii pair<int,int>
using namespace std;

vector <pii> score(101,pii(0,0));

void varClean() {
    vector <pii> empty(101,pii(0,0));
    score.swap(empty);
}

int main() {
	int T = 0;
	int tc = 0;
	int answer = 0;
	int idx = 0;
	int curScore = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &tc);
		for (idx = 1; idx <= 1000; idx++) {
			scanf("%d", &curScore);
			score[curScore].second = curScore;
			score[curScore].first += 1;
		}
		priority_queue <pii> pq(score.begin()+1, score.end());
		printf("#%d %d\n", tc, pq.top().second);
        varClean();
	}
	return 0;
}