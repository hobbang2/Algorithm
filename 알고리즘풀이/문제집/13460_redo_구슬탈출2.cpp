#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

typedef struct Ball {
	int y, x;
	bool gettingHall;
	Ball() {
		y = x = -1;
		gettingHall = false;
	}
	Ball(const Ball & originBall) {
		y = originBall.y;
		x = originBall.x;
		gettingHall = originBall.gettingHall;
	}
}Ball;

vector <vector <char> > map(11, vector <char>(11, '#'));

enum { WEST, SOUTH, EAST, NORTH };

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,1,0,-1 };
int answer = 11;

void mapCheck(int N, int M) {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			printf("%c", map[y][x]);
		}
		printf("\n");
	}
}

void moveBall(Ball & blue, Ball & red, int dy, int dx) {
	int blueMovingDist = 0;
	int redMovingDist = 0;

	int cur_y = blue.y;
	int cur_x = blue.x;

    // blue 공 옮기기
	while (map[cur_y][cur_x] != '#') {
		cur_y = cur_y + dy;
		cur_x = cur_x + dx;
		if (map[cur_y][cur_x] == 'O') {
			blue.y = cur_y;
			blue.x = cur_x;
			blue.gettingHall = true;
			break;
		}
	}
	if (blue.gettingHall != true) {
		blueMovingDist = abs(cur_y - blue.y) + abs(cur_x - blue.x);
		blue.y = cur_y - dy;
		blue.x = cur_x - dx;
	}

	cur_y = red.y;
	cur_x = red.x;

    // red 공 옮기기
	while (map[cur_y][cur_x] != '#') {
		cur_y = cur_y + dy;
		cur_x = cur_x + dx;
		if (map[cur_y][cur_x] == 'O') {
			red.y = cur_y;
			red.x = cur_x;
			red.gettingHall = true;
			break;
		}
	}
	if (red.gettingHall != true) {
		redMovingDist = abs(cur_y - red.y) + abs(cur_x - red.x);
		red.y = cur_y - dy;
		red.x = cur_x - dx;
	}

	if ((red.y == blue.y) && (red.x == blue.x)) {
		if (redMovingDist > blueMovingDist) {
			red.y = red.y - dy;
			red.x = red.x - dx;
		}
		else {
			blue.y = blue.y - dy;
			blue.x = blue.x - dx;
		}
	}
}

void gameStart(Ball & blue, Ball & red, int cnt) {
	if (cnt > 10) {
		return;
	}
	if (blue.gettingHall == true && red.gettingHall == true) {
		return;
	}
	if (blue.gettingHall == true) {
		return;
	}
	if (red.gettingHall == true) {
		answer = (answer > cnt) ? cnt : answer;
		return;
	}

	// 이동거리를 어떻게 재지 !? 
	for (int d = 0; d < 4; d++) {
		if (blue.gettingHall == true || red.gettingHall == true) {
			break;
		}
		Ball nextBlue = blue;
		Ball nextRed = red;

		moveBall(nextBlue, nextRed, dir_y[d], dir_x[d]);
		int blueDist = abs(blue.y - nextBlue.y) + abs(blue.x - nextBlue.x);
		int redDist = abs(red.y - nextRed.y) + abs(red.x - nextRed.x);
        // 지난 번이랑 비교해서 안움직였으면 방향바꾸기
		if ((blueDist == 0) && (redDist == 0) && (nextBlue.gettingHall == false) && (nextRed.gettingHall == false)) {
			continue;
		}
		gameStart(nextBlue, nextRed, cnt + 1);
	}

}


int main() {
	int N = 0, M = 0;
	Ball blueBall, redBall;
	scanf("%d %d", &N, &M);
	getchar();

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			scanf("%c", &map[y][x]);
			if (map[y][x] == 'B') {
				blueBall.y = y;
				blueBall.x = x;
			}
			if (map[y][x] == 'R') {
				redBall.y = y;
				redBall.x = x;
			}
		}
		getchar();
	}

	gameStart(blueBall,redBall,0);
	answer == 11 ? printf("-1\n") : printf("%d\n", answer);
	return 0;
}