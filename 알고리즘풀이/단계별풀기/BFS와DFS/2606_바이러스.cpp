#include <cstdio>
#include <queue>

using namespace std;

int map[101][101] = { 0, };
bool visited[101] = { false, };
int N = 0, connection = 0;

int infection(int num) {
	int cnt = 0;
	queue <int> q;
	q.push(num);
	visited[num] = true;
	int curNum = 0;

	while (q.empty() == false) {
		curNum = q.front(); q.pop();
		for (int c = 1; c <= N; c++) {
			if ((map[curNum][c] == 1) && (visited[c] == false)) {
				visited[c] = true;
				q.push(c);
				cnt += 1;
			}
		}
	}
	return cnt;
}

int main() {
	scanf("%d\n%d", &N, &connection);
	
	int f = 0, s = 0;
	for (int c = 0; c < connection; c++) {
		scanf("%d %d", &f, &s);
		map[f][s] = map[s][f] = 1;
	}

	int answer = 0;
	answer = infection(1);
	printf("%d\n", answer);
	return 0;
}