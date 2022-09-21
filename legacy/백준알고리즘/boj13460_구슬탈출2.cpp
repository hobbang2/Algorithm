#include <iostream>
#include <vector>

using namespace std;

enum { UP, LEFT, DOWN, RIGHT, PATH = 77, WALL, BLUE, RED, GOAL = 777 };
int dir_x[4] = { 0,-1,0,1 };
int dir_y[4] = { -1,0,1,0 };

int COUNT;
int map[11][11];
int N, M;
int result = 999;
bool blueFlag = false, redFlag = false, moveFlag = false;

typedef struct Ball {
	int y;
	int x;
	int color;
	bool reachGoal;
}Ball;

Ball red = { 0,0,RED,false };
Ball blue = { 0,0,BLUE,false };
Ball goal = { 0,0,0,false };

// vector <vector <int> > map(11,vector <int> (11,0));
// vector <vector <int> > initialVec(11,vector <int> (11,0));
void initMap()
{
	for (int y = 0; y < 11; y++)
	{
		for (int x = 0; x < 11; x++)
		{
			map[y][x] = 0;
		}
	}
}

bool isReachGoal(const Ball & target)
{
	if ((target.y == goal.y) && (target.x == goal.x))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool canGo(Ball & movingBall, const Ball & redBall, const Ball & blueBall)
{

	if (movingBall.y < 0 || movingBall.x < 0 || movingBall.y >= N || movingBall.x >= M)
	{
		return false;
	}
	else if (map[movingBall.y][movingBall.x] == WALL)
	{
		return false;
	}
	else if ((movingBall.y == goal.y) && (movingBall.x == goal.x))
	{

		movingBall.reachGoal = true;
		return true;
	}
	else if ((movingBall.color == RED) && ((movingBall.y == blueBall.y) && (movingBall.x == blueBall.x)))
	{
		return false;
	}
	else if ((movingBall.color == BLUE) && ((movingBall.y == redBall.y) && (movingBall.x == redBall.x)))
	{
		return false;
	}

	else
	{
		return true;
	}
}
void moveBall(Ball & movingBall, const Ball & redBall, const Ball & blueBall, int dir)
{
	Ball nextBall = { movingBall.y + dir_y[dir],movingBall.x + dir_x[dir],movingBall.color,movingBall.reachGoal };

	//debugging
	while (canGo(nextBall, redBall, blueBall))
	{

		movingBall = nextBall;
		if ((movingBall.y == goal.y) && (movingBall.x == goal.x))
		{
			break;
		}
		nextBall.y += dir_y[dir];
		nextBall.x += dir_x[dir];

	}

	return;
}


void gameStart(const Ball & redBall, const Ball & blueBall, int cnt, int ex_dir)
{
	if (cnt > 10)
	{
		return;
	}
	if (redBall.reachGoal)
	{
		// cout << "reachGoal : " << cnt << endl;
		if ((!blueBall.reachGoal) && (result > cnt))
		{
			result = cnt;
		}

		return;
	}
	if (blueBall.reachGoal)
	{
		return;
	}

	Ball nextRedBall = { 0,0,RED ,false };
	Ball nextBlueBall = { 0,0,BLUE,false };

	for (int dir = 0; dir < 4; dir++)
	{

		COUNT = cnt;
		nextRedBall = redBall;
		nextBlueBall = blueBall;
		//cout << nextRedBall.y << " " << nextRedBall.x<<endl;
		// UP

		if ((ex_dir == -1 && dir == UP) || (((ex_dir + 2) % 4) != UP && (ex_dir != dir) && (dir == UP)))
		{
			if (redBall.x == blueBall.x)
			{
				if (redBall.y < blueBall.y)
				{
					moveBall(nextRedBall, nextRedBall, nextBlueBall, dir);
					moveBall(nextBlueBall, nextRedBall, nextBlueBall, dir);
				}
				else
				{
					moveBall(nextBlueBall, nextRedBall, nextBlueBall, dir);
					moveBall(nextRedBall, nextRedBall, nextBlueBall, dir);
				}

			}
			else
			{
				moveBall(nextBlueBall, nextRedBall, nextBlueBall, dir);
				moveBall(nextRedBall, nextRedBall, nextBlueBall, dir);

			}
			// printf("UP red BALL %d %d\n", nextRedBall.y, nextRedBall.x);


		}
		// LEFT
		if ((ex_dir == -1 && dir == LEFT) || (((ex_dir + 2) % 4) != LEFT && (ex_dir != dir) && (dir == LEFT)))
		{
			if (redBall.y == blueBall.y)
			{
				if (redBall.x < blueBall.x)
				{
					moveBall(nextRedBall, nextRedBall, nextBlueBall, dir);
					moveBall(nextBlueBall, nextRedBall, nextBlueBall, dir);

				}
				else
				{
					moveBall(nextBlueBall, nextRedBall, nextBlueBall, dir);
					moveBall(nextRedBall, nextRedBall, nextBlueBall, dir);
				}

			}
			else
			{
				moveBall(nextBlueBall, nextRedBall, nextBlueBall, dir);
				moveBall(nextRedBall, nextRedBall, nextBlueBall, dir);
			}



			/*			//DEBUGGING
			if (nextRedBall.y == 5 && nextRedBall.x == 1)
				printf("LEFT COUNT %d\n", cnt);

			printf("LEFT red BALL %d %d\n", nextRedBall.y, nextRedBall.x);
			*/



		}
		// DOWN
		if (((ex_dir == -1) && (dir == DOWN)) || (((ex_dir + 2) % 4) != DOWN && (ex_dir != dir) && (dir == DOWN)))
		{
			if (redBall.x == blueBall.x)
			{
				if (redBall.y < blueBall.y)
				{
					moveBall(nextBlueBall, nextRedBall, nextBlueBall, dir);
					moveBall(nextRedBall, nextRedBall, nextBlueBall, dir);
				}
				else
				{
					moveBall(nextRedBall, nextRedBall, nextBlueBall, dir);
					moveBall(nextBlueBall, nextRedBall, nextBlueBall, dir);
				}
			}
			else
			{
				moveBall(nextRedBall, nextRedBall, nextBlueBall, dir);
				moveBall(nextBlueBall, nextRedBall, nextBlueBall, dir);
			}
			//cout << "DOWN blue BALL "<< nextBlueBall.y<<" "<< nextBlueBall.x<< " " << map[nextBlueBall.y][nextBlueBall.x]<<endl;
			//cout << "DOWN red BALL " << nextRedBall.y << " " << nextRedBall.x << " " << map[nextRedBall.y][nextRedBall.x]<<endl;
			//DEBUGGING


		}

		// RIGHT
		if ((ex_dir == -1 && dir == RIGHT) || (((ex_dir + 2) % 4) != RIGHT && (ex_dir != dir) && dir == RIGHT))
		{
			if (redBall.y == blueBall.y)
			{
				if (redBall.x < blueBall.x)
				{
					moveBall(nextBlueBall, nextRedBall, nextBlueBall, dir);
					moveBall(nextRedBall, nextRedBall, nextBlueBall, dir);
				}
				else
				{
					moveBall(nextRedBall, nextRedBall, nextBlueBall, dir);
					moveBall(nextBlueBall, nextRedBall, nextBlueBall, dir);
				}
			}
			else
			{
				moveBall(nextRedBall, nextRedBall, nextBlueBall, dir);
				moveBall(nextBlueBall, nextRedBall, nextBlueBall, dir);
			}
			//printf("RIGHT red BALL %d %d\n", nextRedBall.y, nextRedBall.x);


		}
		gameStart(nextRedBall, nextBlueBall, cnt + 1, dir);
	}
}


int main()
{
	cin >> N >> M;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			char markCh = ' ';
			cin >> markCh;
			switch (markCh)
			{
			case '#':
				map[y][x] = WALL;
				break;
			case '.':
				map[y][x] = PATH;
				break;
			case 'O':
				map[y][x] = GOAL;
				goal.y = y;
				goal.x = x;
				goal.color = GOAL;
				break;
			case 'B':
				map[y][x] = BLUE;
				blue.y = y;
				blue.x = x;
				blue.color = BLUE;

				break;
			case 'R':
				map[y][x] = RED;
				red.y = y;
				red.x = x;
				red.color = RED;

				break;
			}
		}
	}

	gameStart(red, blue, 0, -1);
	cout << (result == 999 ? -1 : result);
	return 0;
}