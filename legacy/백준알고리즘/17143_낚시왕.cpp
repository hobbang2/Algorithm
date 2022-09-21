#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>


using namespace std;

enum { UP = 1, DOWN, RIGHT, LEFT };

int dir_x[5] = { -999,0,0,1,-1 };
int dir_y[5] = { -999,-1,1,0,0 };

typedef struct Shark {
	int y, x;
	int s, d, z;
	int life;
	Shark(int _y, int _x, int _s, int _d, int _z, int _life) :y(_y), x(_x), s(_s), d(_d), z(_z), life(_life) {
	}
	Shark() {
		y = x = s = d = z = life = 0;
	}
}Shark;

vector <Shark> sharks;
vector <vector<int> > map(101, vector<int>(101, 0));
int R = 0, C = 0, M = 0;

void changeDir(Shark & target) {
	switch (target.d) {
	case UP:
		target.d = DOWN;
		break;
	case DOWN:
		target.d = UP;
		break;
	case RIGHT:
		target.d = LEFT;
		break;
	case LEFT:
		target.d = RIGHT;
		break;
	}
}

void moveShark() {
	vector <vector <int> > next_map(101, vector<int>(101, 0));
	int sharkNum = (int)sharks.size();

	for (int idx = 1; idx < sharkNum; idx++) {
		if (sharks[idx].life == false) {
			continue;
		}
		int curSpeed = sharks[idx].s;
		int next_y = sharks[idx].y, next_x = sharks[idx].x;
		if (sharks[idx].d <= 2) {
			curSpeed = curSpeed % ((R - 1) * 2);
		}
		else {
			curSpeed = curSpeed % ((C - 1) * 2);
		}
		for (int s = 1; s <= curSpeed; s++) {
			next_y = next_y + dir_y[sharks[idx].d];
			next_x = next_x + dir_x[sharks[idx].d];
			if ((next_y == 0) || (next_y > R)) {
				changeDir(sharks[idx]);
				next_y = next_y + 2 * dir_y[sharks[idx].d];
			}
			if ((next_x == 0) || (next_x > C)) {
				changeDir(sharks[idx]);
				next_x = next_x + 2 * dir_x[sharks[idx].d];
			}
		}
		int next_idx = next_map[next_y][next_x];
		if (sharks[next_idx].z > sharks[idx].z) {
			sharks[idx].life = false;
			continue;
		}
		sharks[next_idx].life = false;
		next_map[next_y][next_x] = idx;
		sharks[idx].y = next_y;
		sharks[idx].x = next_x;
	}
	map.swap(next_map);
}

int main() {
	int result = 0;
	Shark mimicShark, curShark;
	sharks.push_back({ -1,-1,-1,-1,-1,false });

	scanf("%d %d %d", &R, &C, &M);

	if (M > 0)
	{
		for (int m = 1; m <= M; m++) {
			int y = 0, x = 0, s = 0, d = 0, z = 0;
			scanf("%d %d %d %d %d", &y, &x, &s, &d, &z);
			curShark = { y,x,s,d,z,true };
			sharks.push_back(curShark);
			map[y][x] = m;
		}

		// 물고기를 잡아보자. 
		for (int x = 1; x <= C; x++) {
			for (int y = 1; y <= R; y++) {
				if (map[y][x] != 0) {
					result += sharks[map[y][x]].z;
					sharks[map[y][x]].life = false;
					break;
				}
			}
			moveShark();
		}
	}

	printf("%d\n", result);
	return 0;
}