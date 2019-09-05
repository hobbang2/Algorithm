#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int N = 0;
int map[101][101];
int dir_x[4] = { 1,0,-1,0 };
int dir_y[4] = { 0,-1,0,1 };

typedef struct Curve {
	int y, x;
	int d;
	int gene;
}Curve;

vector <Curve> dragonCurve;

void initVector(vector <Curve> & targetVec) {
	vector <Curve> emptyVec;
	targetVec.swap(emptyVec);
	return;
}

void gameStart(const Curve & initCurve) {
	dragonCurve.push_back(initCurve);

	for (int cnt = 1; cnt <= initCurve.gene; cnt++) {
		int pointNum = (int)dragonCurve.size();
		Curve lastCurve = dragonCurve.back();

		for (int num = 0; num < pointNum; num++) {
			Curve curCurve = dragonCurve[num];
			map[curCurve.y][curCurve.x] = cnt;
			Curve nextCurve = {0,};
			if (cnt == 1) {
				nextCurve.y = curCurve.y + dir_y[curCurve.d];
				nextCurve.x = curCurve.x + dir_x[curCurve.d];
			}
			else {
				nextCurve.y = (100 - curCurve.x) + lastCurve.y - 50;
				nextCurve.x = curCurve.y + lastCurve.x - 50;
			}
			dragonCurve.push_back(nextCurve);
		}
	}
}


int main() {
	scanf("%d", &N);

	for (int n = 1; n <= N; n++) {
		Curve curCurve = {0,};
		scanf("%d %d %d %d", &curCurve.x, &curCurve.y, &curCurve.d, &curCurve.gene);
		curCurve.y += 50;
		curCurve.x += 50;
		curCurve.gene += 1;
		gameStart(curCurve);
		initVector(dragonCurve);
	}

	int ans = 0;
	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			printf("%d ", map[y][x]);
			if ((map[y][x] != 0)&& (map[y][x + 1]!=0)&&(map[y + 1][x]!=0)&&(map[y + 1][x + 1]!=0)) {
				ans++;
			}
		}
		printf("\n");
	}

	printf("%d ", ans);

	return 0;
}#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int N = 0;
int map[101][101];
int dir_x[4] = { 1,0,-1,0 };
int dir_y[4] = { 0,-1,0,1 };

typedef struct Curve {
	int y, x;
	int d;
	int gene;
}Curve;

vector <Curve> dragonCurve;

void initVector(vector <Curve> & targetVec) {
	vector <Curve> emptyVec;
	targetVec.swap(emptyVec);
	return;
}

void gameStart(const Curve & initCurve) {
	dragonCurve.push_back(initCurve);
	int compDist = 0;
	Curve lastCurve = { 0, };

	for (int cnt = 1; cnt <= initCurve.gene; cnt++) {
		int pointNum = (int)dragonCurve.size();

		for (int num = 0; num < pointNum; num++) {
			Curve curCurve = dragonCurve[num];
			map[curCurve.y][curCurve.x] = cnt;
			Curve nextCurve = {0,};

			if (cnt == 1) {
				nextCurve.y = curCurve.y + dir_y[curCurve.d];
				nextCurve.x = curCurve.x + dir_x[curCurve.d];
				lastCurve = nextCurve;
			}
			else {
				nextCurve.y = (100 - curCurve.x) + lastCurve.y - 50;
				nextCurve.x = curCurve.y + lastCurve.x - 50;
				int curDist = (nextCurve.y - initCurve.y)*(nextCurve.y - initCurve.y) + (nextCurve.x - initCurve.x)*(nextCurve.x- initCurve.x);
				if (curDist >=compDist) {
					compDist = curDist;
					lastCurve = nextCurve;
				}
			}
			dragonCurve.push_back(nextCurve);
		}
	}
}


int main() {
	scanf("%d", &N);

	for (int n = 1; n <= N; n++) {
		Curve curCurve = {0,};
		scanf("%d %d %d %d", &curCurve.x, &curCurve.y, &curCurve.d, &curCurve.gene);
		curCurve.y += 50;
		curCurve.x += 50;
		curCurve.gene += 1;
		gameStart(curCurve);
		initVector(dragonCurve);
	}

	int ans = 0;
	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			printf("%d ", map[y][x]);
			if ((map[y][x] != 0)&& (map[y][x + 1]!=0)&&(map[y + 1][x]!=0)&&(map[y + 1][x + 1]!=0)) {
				ans++;
			}
		}
		printf("\n");
	}

	printf("%d ", ans);

	return 0;
}