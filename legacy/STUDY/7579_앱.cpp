#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

/*https://organize-study.tistory.com/63*/
int main() {
	int N = 0, M = 0;
	int cost = 10001;
	int maxCost = 0;
	int costMemory[10001] = {0,};

	scanf("%d %d", &N, &M);
	vector <pair<int, int> > apps(N+1,pair<int,int> (0,0));
	for (int n = 1; n <= N; n++) {
		scanf("%d", &apps[n].first);
	}

	for (int n = 1; n <= N; n++) {
		scanf("%d", &apps[n].second);
		maxCost += apps[n].second;
		/*if ((apps[n].first >= M) && cost < apps[n].second) {
			cost = apps[n].second;
		}*/
	}

	for (int idx = 1; idx <= N; idx++) {
		for (int c = maxCost; c >= apps[idx].second; c--) {
			costMemory[c] = max(costMemory[c], costMemory[c - apps[idx].second]+apps[idx].first);
		}
	}

	int ans = 0;
	for (; (ans < maxCost) && (costMemory[ans] < M); ans++);

	printf("%d\n", ans);

	return 0;
}