#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum { NORTH, EAST, SOUTH, WEST };
typedef struct Coord {
	int y, x;
	int dir;
}Coord;

char map[21][21];
// 북동남서
int R, C;
int dirY[4] = { -1,0,1,0 };
int dirX[4] = { 0,1,0,-1 };

void rangeChk(int & y, int & x) {
	if (y <= 0) {
		y = R;
	}
	else if (x <= 0) {
		x = C;
	}
	else if (y > R) {
		y = 1;
	}
	else if (x > C) {
		x = 1;
	}
	return;
}

bool startProgramming(int y, int x) {
	int visited[21][21][16][4] = { 0, };
	int memory = 0;
	queue <Coord> q;
	q.push({ y,x,EAST });
	visited[y][x][memory][EAST] = true;
	int qSize = 0;
	int nextX = 0, nextY = 0, curDir = 0;

	while (q.empty() == false) {
		Coord curCoord = q.front(); q.pop();
		char curChar = map[curCoord.y][curCoord.x];
		if (curChar == '@') {
			return true;
		}

		if (curChar >= '0' && curChar <= '9') {
			memory = (curChar - '0');
		}
		else {

			switch (curChar) {
			case '<':
				curCoord.dir = WEST;
				break;
			case '>':
				curCoord.dir = EAST;
				break;
			case '^':
				curCoord.dir = NORTH;
				break;
			case 'v':
				curCoord.dir = SOUTH;
				break;
			case '_':
				curCoord.dir = (memory == 0) ? EAST : WEST;
				break;
			case '|':
				curCoord.dir = (memory == 0) ? SOUTH : NORTH;
				break;
			case '?':
				for (int d = 0; d < 4; d++) {
					nextY = curCoord.y + dirY[d];
					nextX = curCoord.x + dirX[d];
					rangeChk(nextY, nextX);
					if (visited[nextY][nextX][memory][d] == false) {
						visited[nextY][nextX][memory][d] = true;
						q.push({ nextY,nextX,d });
					}
				}
				continue;
			case '+':
				memory = (memory == 15) ? 0 : memory + 1;
				break;
			case '-':
				memory = (memory == 0) ? 15 : memory - 1;
			}
		}
        curDir = curCoord.dir;
        nextY = curCoord.y + dirY[curDir];
        nextX = curCoord.x + dirX[curDir];
        rangeChk(nextY, nextX);
        if (visited[nextY][nextX][memory][curDir] == false) {
            visited[nextY][nextX][memory][curDir] = true;
            q.push({ nextY,nextX,curDir });
        }
        // 같은 좌표, 방향, 메모리를 가지는 곳에 방문한 곳이 있으면 무한루프에 빠지는 것이므로 queue에 삽입X
	}
	return false;
}
int main() {
	int T = 0;
	int tc = 0;
	int answer = 0;
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> R >> C;
		for (int r = 1; r <= R; r++) {
			for (int c = 1; c <= C; c++) {
				cin >> map[r][c];
			}
		}
		cout << "#" << tc << " ";
		(startProgramming(1, 1) == true) ? cout << "YES\n" : cout << "NO\n";
	}
	return 0;
}