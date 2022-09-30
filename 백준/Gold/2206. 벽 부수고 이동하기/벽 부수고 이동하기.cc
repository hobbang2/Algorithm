#include <iostream>
#include <queue>
using namespace std;
int ret = 100000, m, n;
char arr[1001][1001];
//[0] 벽을 안부쉈을 때 경로, [1] 벽을 부쉈을 때 경로
int check[1001][1001][2];
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
struct QQ {
	int r, c, w;
};

int bfs() {
	queue<QQ> q;
	q.push({ 0,0,0 });
	check[0][0][0] = 1;
	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int w = q.front().w;
		q.pop();
		if (r == n - 1 && c == m - 1) return check[r][c][w];
		for (int i = 0; i < 4; ++i) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= m || check[nr][nc][w] != 0)continue;
			//땅이면
			if (arr[nr][nc] == '0') {
				check[nr][nc][w] = check[r][c][w] + 1;
				q.push({ nr,nc,w });
			}
			//벽이면서 벽 부술 수 있으면
			if (arr[nr][nc] == '1' && w == 0) {
				check[nr][nc][1] = check[r][c][w] + 1;
				q.push({ nr,nc,1 });
			}
			
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	cout << bfs();
	return 0;
}