#include <cstdio>
#include <vector>
#include <queue>

using namespace std;


typedef struct User {
	int y, x;
	int curCharge;
	int curIdx;
	int curSum;
	User(int _y = 0, int _x =0, int _curCharge = 0, int _curIdx = 0, int _curSum = 0) :
		y(_y), x(_x), curCharge(_curCharge), curIdx(_curIdx), curSum(_curSum) {
	}
}User;

typedef struct Charger {
	int id;
	int y, x;
	int c;
	int p;
	Charger(int _id = -1,int _y = 0, int _x = 0, int _c = 0, int _p = 0) :id(_id),y(_y), x(_x), c(_c), p(_p) {

	}
}Charger;


int M, A;

queue <int> aQ;
queue <int> bQ;
queue <Charger> chargeQ;
vector <int> map[11][11];
int cntMap[11][11];
vector <int> battery(9,0);

User userA(1, 1);
User userB(10, 10);

void cleaner() {

}

int dirY[5] = { 0,-1,0,1,0 };
int dirX[5] = { 0,0,1,0,-1 };

bool isInMap(int y, int x) {
	if (y <= 0 || x <= 0 || y > 10 || x > 10) {
		return false;
	}
	return true;
}

void getChargeRange() {
	while (chargeQ.empty() == false) {
		Charger curCharger = chargeQ.front(); chargeQ.pop();
		if (curCharger.c == 0) {
			continue;
		}
		for (int d = 1; d < 5; d++) {
			Charger nextCharger = curCharger;
			int nextY = curCharger.y + dirY[d];
			int nextX = curCharger.x + dirX[d];
			if (isInMap(nextY, nextX) ==false) {
				continue;
			}
			nextCharger.y = nextY, nextCharger.x = nextX;
			nextCharger.c -= 1;
			cntMap[nextY][nextX] += 1;
			map[nextY][nextX].push_back(nextCharger.id);
			chargeQ.push(nextCharger);
		}
	}
}

pair<int, int> findMaxValue(vector <int> vec,int except = -1) {
	int maxIdx = -1, maxValue = -1;
	for (int v = 0; v < (int)vec.size(); v++) {
		if (except != -1 && vec[v] == except) {
			continue;
		}
		if (battery[vec[v]] > maxValue) {
			maxValue = battery[vec[v]];
			maxIdx = vec[v];
		}
	}
	return make_pair(maxIdx, maxValue);
}

void checkUserLoc() {
	if (cntMap[userA.y][userA.x] >= 1) {
		if (cntMap[userA.y][userA.x] == 1) {
			userA.curIdx = map[userA.y][userA.x].front();
			userA.curCharge = battery[userA.curIdx];
		}
		else {
			pair <int, int> maxPair = findMaxValue(map[userA.y][userA.x]);
			userA.curIdx = maxPair.first;
			userA.curCharge = maxPair.second;
		}
	}
	if (map[userB.y][userB.x].empty() == false) {
		if (cntMap[userB.y][userB.x] == 1) {
			userB.curIdx = map[userB.y][userB.x].front();
			userB.curCharge = battery[userB.curIdx];
		}
		else {
			pair <int, int> maxPair = findMaxValue(map[userB.y][userB.x]);
			userB.curIdx = maxPair.first;
			userB.curCharge = maxPair.second;
		}
	}
	if (userA.curIdx == userB.curIdx) {
		if (userA.y == userB.y && userA.x == userB.x) {
			if (cntMap[userB.y][userB.x] == 1) {
				userA.curCharge /= 2;
				userB.curCharge /= 2;
			}
			else {
				pair <int, int> maxPair = findMaxValue(map[userB.y][userB.x],userB.curIdx);
				userB.
			}
		}
	}
}

void moveUser() {
	checkUserLoc();
	for (int m = 1; m <= M; m++) {
		User aNext = userA;
		User bNext = userB;
		int aD = aQ.front(); aQ.pop();
		int bD = bQ.front(); bQ.pop();
		aNext.y = aNext.y + dirY[aD];
		aNext.y = aNext.y + dirY[aD];
		bNext.y = bNext.y + dirY[bD];
		bNext.x = bNext.x + dirX[bD];
		if ((aD != 0) && (isInMap(aNext.y, aNext.y) == true)) {
			aNext.curSum = aNext.curCharge;
			battery[aNext.curIdx] += aNext.curCharge;

		}
	}
}

int main() {
	int T = 0,tc = 1; 
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) {
		scanf("%d %d", &M, &A);
		int dir = 0;
		for (int m = 1; m <= M; m++) {
			scanf("%d", &dir);
			aQ.push(dir);
		}
		for (int m = 1; m <= M; m++) {
			scanf("%d", &dir);
			bQ.push(dir);
		}
		for (int a = 1; a <= A; a++) {
			int idx = a;
			int x = 0, y = 0, c = 0, p = 0;
			scanf("%d %d %d %d", &x, &y, &c, &p);
			cntMap[y][x] += 1;
			map[y][x].push_back(idx);
			battery[idx] = p;
			Charger tmpCharger(idx,y,x,c,p);
			chargeQ.push(tmpCharger);
		}

		getChargeRange();

	}
	return 0;
}