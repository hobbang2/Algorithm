#include <cstdio>
#include <queue>

using namespace std;

#define MAX_LOC 100000
// 수빈이랑 동생 

bool visited[100001] = { false ,};
queue <int> subin;

bool isInRange(int coord) {
	if (coord < 0 || coord > MAX_LOC) {
		return false;
	}
	return true;
}

void subinMove(int coord) {
	int nextCoord = 0;

	nextCoord = coord * 2;
	if (isInRange(nextCoord) == true && visited[nextCoord] == false) {
		visited[nextCoord] = true;
		subin.push(nextCoord);
	}
	nextCoord = coord + 1;
	if (isInRange(nextCoord) == true && visited[nextCoord] == false) {
		visited[nextCoord] = true;
		subin.push(nextCoord);
	}
	nextCoord = coord - 1;
	if (isInRange(nextCoord) == true && visited[nextCoord] == false) {
		visited[nextCoord] = true;
		subin.push(nextCoord);
	}

}

int gameStart(int K) {
	int qSize =0;
	int cnt = 0;
	int curCoord = 0;
	int state = -10;
	while (subin.empty() == false) {
		cnt += 1;
		qSize = (int)subin.size();
		for (int s = 0; s < qSize; s++) {
			curCoord = subin.front(); subin.pop();
			if (curCoord == K) {
				return cnt;
			}
			subinMove(curCoord);
		}
	}
}

int main() {
	int N = 0, K = 0;
	scanf("%d %d", &N, &K);
	int ans = 0;
	if (N != K) {
		visited[N] = true;
		subinMove(N);
		ans = gameStart(K);
	}
	printf("%d\n", ans);
	return 0;
}