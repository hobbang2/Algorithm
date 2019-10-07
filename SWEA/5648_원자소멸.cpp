#include <cstdio>
#include <vector>
#include <utility>
#include <set>

using namespace std;

enum {UP,DOWN,LEFT,RIGHT,RESULT};
int dir_y[4] = { -1,1,0,0 };
int dir_x[4] = { 0,0,-1,1 };

typedef struct Atom {
	int y, x;
	int energy;
	int dir;
	bool collision;
	Atom(int _y = 0, int _x = 0, int _energy = 0,int _dir=0, bool _collision = false) :y(_y), x(_x), energy(_energy),dir(_dir), collision(_collision) {}
};
vector <Atom> atoms[5];

void initVec(vector <Atom> vec[]) {
	for (int idx = 0; idx < 5; idx++) {
		vector <Atom> emptyVec;
		vec[idx].swap(emptyVec);
	}
}

void upAndDown(vector <Atom> & up, vector <Atom> & down) {
	int upSize = (int)up.size();
	int downSize = (int)down.size();
	for (int u = 0; u < upSize; u++) {
		for (int d = 0; d < downSize; d++) {
			if ((up[u].collision == true) &&(down[d].collision == true)) {
				continue;
			}
			if ((up[u].x == down[d].x) && (down[d].y >= up[u].y)) {
				up[u].collision = true;
				down[d].collision = true;
			}
		}
	}
}

void leftAndRight(vector <Atom> & left, vector <Atom> & right) {
	int leftSize = (int)left.size();
	int rightSize = (int)right.size();
	for (int l = 0; l < leftSize; l++) {
		for (int r = 0; r < rightSize; r++) {
			if ((left[l].collision == true) && (right[r].collision == true)) {
				continue;
			}
			if ((left[l].y == right[r].y) && (left[l].x >= right[r].x)) {
				left[l].collision = true;
				right[r].collision = true;
			}
		}
	}
}

void downAndLeft(vector <Atom> & down, vector <Atom> & left) {
	int downSize = (int)down.size();
	int leftSize = (int)left.size();
	for (int d = 0; d < downSize; d++) {
		for (int l = 0; l < leftSize; l++) {
			if ((down[d].collision == true) && (left[l].collision == true)) {
				continue;
			}
			int diff_x = left[l].x - down[d].x;
			int diff_y = down[d].y - left[l].y;
			if (diff_x == diff_y) {
				down[d].collision = true;
				left[l].collision = true;
			}
		}
	}
}

void downAndRight(vector <Atom> & down, vector <Atom> & right) {
	int downSize = (int)down.size();
	int rightSize = (int)right.size();
	for (int d = 0; d < downSize; d++) {
		for (int r = 0; r < rightSize; r++) {
			if ((down[d].collision == true) && (right[r].collision == true)) {
				continue;
			}
			int diff_x = down[d].x - right[r].x;
			int diff_y = down[d].y - right[r].y;
			if (diff_x == diff_y) {
				down[d].collision = true;
				right[r].collision = true;
			}
		}
	}
}

void upAndRight(vector <Atom> & up, vector <Atom> & right) {
	int upSize = (int)up.size();
	int rightSize = (int)right.size();
	for (int u = 0; u < upSize; u++) {
		for (int r = 0; r < rightSize; r++) {
			if ((up[u].collision == true) && (right[r].collision == true)) {
				continue;
			}
			int diff_x = up[u].x - right[r].x;
			int diff_y = right[r].y - up[u].y;
			if (diff_x == diff_y) {
				up[u].collision = true;
				right[r].collision = true;
			}
		}
	}
}

void upAndLeft(vector <Atom> & up, vector <Atom> & left) {
	int upSize = (int)up.size();
	int leftSize = (int)left.size();
	for (int u = 0; u < upSize; u++) {
		for (int l = 0; l < leftSize; l++) {
			if ((up[u].collision == true) && (left[l].collision == true)) {
				continue;
			}
			int diff_x = left[l].x - up[u].x;
			int diff_y = left[l].y - up[u].y;
			if (diff_x == diff_y) {
				up[u].collision = true;
				left[l].collision = true;
			}
		}
	}
}

int calEnergy(vector <Atom> vec[]) {
	int answer = 0;
	for (int dir = 0; dir < 4; dir++) {
		int vecSize = vec[dir].size();
		for (int idx = 0; idx < vecSize; idx++) {
			if (vec[dir][idx].collision == true) {
				answer += vec[dir][idx].energy;
			}
		}
	}
}

int main() {
	int T = 0;
	int numOfAtoms = 0;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		int answer = 0;
		scanf("%d", &numOfAtoms);
		// 원자 받아오기 
		for (int idx = 1; idx <= numOfAtoms; idx++) {
			int y = 0, x = 0, dir = 0, K = 0;
			scanf("%d %d %d %d", &x, &y, &dir, &K);
			Atom curAtom(y, x, dir, K);
			atoms[dir].push_back(curAtom);
		}
		upAndDown(atoms[UP], atoms[DOWN]);
		upAndLeft(atoms[UP], atoms[LEFT]);
		upAndRight(atoms[UP], atoms[RIGHT]);
		downAndLeft(atoms[DOWN], atoms[LEFT]);
		downAndRight(atoms[DOWN], atoms[RIGHT]);
		leftAndRight(atoms[LEFT], atoms[RIGHT]);

		

		printf("#%d %d\n", tc, answer);
	}

	return 0;
}