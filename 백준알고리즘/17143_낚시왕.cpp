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
	Shark(int _y, int _x, int _s, int _d, int _z) :y(_y), x(_x), s(_s), d(_d), z(_z) {
	}
	Shark() {
		y = x = s = d = z = 0;
	}
}Shark;

vector <Shark> sharks;
vector <vector<Shark> > map(101, vector<Shark>(101, { 0,0,0,0,0 }));
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
	vector <vector<Shark> > next_map(101, vector<Shark>(101, { 0,0,0,0,0 }));

	Shark mimic;
	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			if (map[y][x].z != 0) {
				int curSpeed = map[y][x].s;
				int next_y = y, next_x = x;
				if (map[y][x].d <= 2) {
					curSpeed = curSpeed % ((R - 1) * 2);
				}
				else { //좌우로 움직이는 경우
					curSpeed = curSpeed % ((C - 1) * 2);
				}


				for (int s = 1; s <= curSpeed; s++) {
					next_y = next_y + dir_y[map[y][x].d];
					next_x = next_x + dir_x[map[y][x].d];
					if ((next_y == 0) || (next_y > R)) {
						changeDir(map[y][x]);
						next_y = next_y + 2 * dir_y[map[y][x].d];

					}
					if ((next_x == 0) || (next_x > C)) {
						changeDir(map[y][x]);
						next_x = next_x + 2 * dir_x[map[y][x].d];
					}
				}

				if (next_map[next_y][next_x].z > map[y][x].z) {
					map[y][x] = mimic;
					continue;
				}
				map[y][x].y = next_y, map[y][x].x = next_x;
				next_map[next_y][next_x] = map[y][x];
				map[y][x] = mimic;
			}
		}
	}
	map.swap(next_map);
}

int main() {
	int result = 0;
	Shark mimicShark, curShark;

	scanf("%d %d %d", &R, &C, &M);

	if (M > 0)
	{
		for (int m = 1; m <= M; m++) {
			int y = 0, x = 0, s = 0, d = 0, z = 0;
			scanf("%d %d %d %d %d", &y, &x, &s, &d, &z);
			curShark = { y,x,s,d,z };
			map[y][x] = curShark;
		}

		// 물고기를 잡아보자. 
		for (int x = 1; x <= C; x++) {
			for (int y = 1; y <= R; y++) {
				if (map[y][x].z != 0) {
					result += map[y][x].z;
					map[y][x] = mimicShark;
					break;
				}
			}
			moveShark();
		}
	}

	printf("%d\n", result);
	return 0;
}