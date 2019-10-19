#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>

#define MAX_N 11

using namespace std;

enum { A = 1, B };

typedef struct User {
	int y, x;
}User;

typedef struct Charger {
	int idx;
	int y, x;
	int c;
	int p;
}Charger;

int dirY[5] = { 0,-1,0,1,0 };
int dirX[5] = { 0,0,1,0,-1 };

int M;
int AA;
int answer;
User user[3];
Charger charger[9];
bool used[9];
int userDir[3][101];

void cleaner() {
	memset(charger, 0, sizeof(charger));
	memset(user, 0, sizeof(user));
	memset(used, 0, sizeof(used));
	memset(userDir, 0, sizeof(userDir));
	answer = 0;
}

bool isInChargeArea(int userNum, int chargeIdx) {
	if ((abs(charger[chargeIdx].y - user[userNum].y) + abs(charger[chargeIdx].x - user[userNum].x)) <= charger[chargeIdx].c) {
		return true;
	}
	return false;
}

int curValue = 0;
void getCharge(int userNum, int charge) {
	if (userNum > 2) {
		curValue = (curValue < charge) ? charge : curValue;
		return;
	}

	for (int a = 1; a <= AA; a++) {
		if ((isInChargeArea(userNum, a) == true) && (used[a] == false)) {
			used[a] = true;
			getCharge(userNum + 1, charge + charger[a].p);
			used[a] = false;
		}
	}
	getCharge(userNum + 1, charge);
	return;
}

int getAnswer(int userName, int charge) {
	curValue = 0;
	getCharge(userName, charge);
	return curValue;

}

int main() {
	int  T = 0, tc = 1;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) {
		scanf("%d %d", &M, &AA);
		for (int m = 1; m <= M; m++) {
			scanf("%d", &userDir[A][m]);
		}
		for (int m = 1; m <= M; m++) {
			scanf("%d", &userDir[B][m]);
		}

		for (int a = 1; a <= AA; a++) {
			charger[a].idx = a;
			scanf("%d %d %d %d", &charger[a].x, &charger[a].y, &charger[a].c, &charger[a].p);
		}

		user[A].y = 1, user[A].x = 1, user[B].y = 10, user[B].x = 10;
		answer += getAnswer(1, 0);

		for (int m = 1; m <= M; m++) {
			int aDir = userDir[A][m];
			int bDir = userDir[B][m];
			user[A].y += dirY[aDir];
			user[A].x += dirX[aDir];
			user[B].y += dirY[bDir];
			user[B].x += dirX[bDir];
			answer += getAnswer(1, 0);
		}

		printf("#%d %d\n", tc, answer);
		cleaner();
	}
	return 0;
}