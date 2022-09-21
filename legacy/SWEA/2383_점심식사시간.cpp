#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#define INF 10000
#define MAXT 250
#define MAXN 11

int N, M, S;
int map[MAXN][MAXN];
int ans = INF;

typedef struct Position {
	int y, x;
	int sNum;
	Position() {};
	Position(int _y, int _x,int _n=0) :y(_y), x(_x),sNum(_n) {};
}Position;

Position people[MAXN];
Position stair[2];

void init() {
	N = 0, M = 0, S = 0;
	ans = INF;
	memset(map, 0, sizeof(map));
}

int getDist(const Position & p, const Position & s) {
	return abs(p.y - s.y) + abs(p.x - s.x);
}

void update() {
	int result = 0;
	for (int sIdx = 0; sIdx < 2; sIdx++) {
		int arrT[MAXN * 2 + 1] = { 0, };
		int curStair[MAXT] = { 0, };
		for (int mIdx = 0; mIdx < M; mIdx++) {
			if (people[mIdx].sNum == sIdx) {
				int curDist = getDist(people[mIdx], stair[sIdx]);
				arrT[curDist + 1]++;
			}
		}
		int curMinT = 0;
		for (int time = 1; time <= 20; time++) {
			while (arrT[time] > 0) {
				arrT[time]--;
				int sY = stair[sIdx].y, sX = stair[sIdx].x;
				int remain = map[sY][sX];
				for (int wT = time; wT < MAXT; wT++) {
					if (curStair[wT] < 3) {
						curStair[wT]++;
						remain--;
						if (remain == 0) {
							curMinT = (curMinT > wT + 1) ? curMinT : wT + 1;
							break;
						}
					}
				}
			}
		}
		result = (result > curMinT) ? result : curMinT;
	}
	ans = (ans > result) ? result : ans;
}

void getAnswer(int idx) {
	if (idx == M) {
		update();
		return;
	}
	for (int s = 0; s < 2; s++) {
		people[idx].sNum = s;
		getAnswer(idx + 1);
	}
}

int main() {
	int T = 0, tc = 0;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) {
		scanf("%d", &N);
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				scanf("%d", &map[y][x]);
				if (map[y][x] == 1) {
					people[M++] = Position(y, x);
				}
				else if (map[y][x] > 1) {
					stair[S++] = Position(y, x);
				}
			}
		}
		getAnswer(0);
		printf("#%d %d\n", tc,ans);
		init();
	}
	return 0;
}