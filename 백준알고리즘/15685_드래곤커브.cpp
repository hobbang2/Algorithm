#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int N = 0;
int map[101][101];
int dir_x[4] = { 1,0,-1,0 };
int dir_y[4] = { 0,-1,0,1 };

vector <int> dragonCurve;

void initVector(vector <int> & targetVec) {
	vector <int> emptyVec;
	targetVec.swap(emptyVec);
	return;
}

void makeDragonCurve(int dir, int generation) {
	dragonCurve.push_back(dir);
	for (int gene = 1; gene <= generation; gene++) {
		int curveSize = (int)dragonCurve.size();
		for (int idx = curveSize-1; idx >= 0; idx--) {
			int nextDir = (dragonCurve[idx] + 1) % 4;
			dragonCurve.push_back(nextDir);
		}
	}
}

void drawDragonCurve(int y,int x){
	int curveSize = (int)dragonCurve.size();
	map[y][x] = 1;
	for (int idx = 0; idx < curveSize; idx++) {
		y += dir_y[dragonCurve[idx]];
		x += dir_x[dragonCurve[idx]];
		map[y][x] = 1;
	}
}


int main() {
	scanf("%d", &N);

	for (int n = 1; n <= N; n++) {
		initVector(dragonCurve);
		int curX = 0, curY = 0,curD = 0, curGene =0;
		scanf("%d %d %d %d", &curX, &curY, &curD, &curGene);
		makeDragonCurve(curD,curGene);
		drawDragonCurve(curY,curX);
	}

	int ans = 0;
	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			if ((map[y][x])& (map[y][x + 1])&(map[y + 1][x])&(map[y + 1][x + 1])) {
				ans++;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}