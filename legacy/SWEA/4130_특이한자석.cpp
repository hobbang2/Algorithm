#include <cstdio>
#include <vector>
#include <cstdlib>


using namespace std;

enum {LEFT =  0 , RIGHT =1};

bool visited[4] = { false, };

struct topni {
	vector <int> wheel;
	int indicator;
	topni() {
		indicator = 0;
		wheel.resize(8);
	}
}topni[4];

void lotation(int num, int dir) {
	if (num > 3||num < 0 || dir == 0) {
		return;
	}
	visited[num] = true;
	
	for (int d = 0; d < 2; d++) {
        // 각 방향에 자석이 있고 방문한 적이 없으면 회전하러 ㄱㄱ 
		if (d == LEFT) {
			if (num - 1 >= 0 && visited[num - 1] == false) {
				int nextDir = 0;
				int curFaceIndi = (topni[num].indicator + 6) % 8;
				int nextFaceIndi = (topni[num - 1].indicator + 2) % 8;
				int curFace = topni[num].wheel[curFaceIndi];
				int nextFace = topni[num - 1].wheel[nextFaceIndi];

				nextDir = (curFace == nextFace) ? 0 : -dir;
				lotation(num - 1, nextDir);
			}
		}
		if (d == RIGHT) {
			if (num + 1 < 4 && visited[num + 1] == false) {
				int nextDir = 0;
				int curFaceIndi = (topni[num].indicator + 2) % 8;
				int nextFaceIndi = (topni[num + 1].indicator + 6) % 8;
				int curFace = topni[num].wheel[curFaceIndi];
				int nextFace = topni[num + 1].wheel[nextFaceIndi];

				nextDir = (curFace == nextFace) ? 0 : -dir;
				lotation(num + 1, nextDir);
			}
		}
	}
	
	// 시계방향이면 왼쪽으로 한칸, 반시계면 오른쪽으로 한칸
	topni[num].indicator += ((dir == 1) ? -1 : 1);
	if (topni[num].indicator < 0) {
		topni[num].indicator += 8;
	}
	topni[num].indicator %= 8;
}

int calScore() {
	int score = 0;
	int baseScore = 1;
	for (int n = 0; n < 4; n++) {
		int curIndi = topni[n].indicator;
		if (topni[n].wheel[curIndi] == 1) {
			score += baseScore;
		}
		baseScore *= 2;
	}
	return score;
}

int main() {
	setbuf(stdout, NULL);
	freopen("input.txt", "r", stdin);
	int T = 0;
	int K = 0;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &K);

		for (int n = 0; n < 4; n++) {
			topni[n].indicator = 0;
			for (int w = 0; w < 8; w++) {
				scanf("%d", &topni[n].wheel[w]);
			}
		}

		for (int k = 0; k < K; k++) {
			int n = 0, d = 0;
			scanf("%d %d", &n, &d);
			lotation(n - 1, d);
			memset(visited, false, sizeof(visited));
		}
		int ans = calScore();
		printf("#%d %d\n",tc, ans);
	}
	return 0;
}