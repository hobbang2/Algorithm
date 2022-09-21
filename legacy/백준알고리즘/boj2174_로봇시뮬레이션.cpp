#include <cstdio>
#include <vector>

using namespace std;
enum{SOUTH,EAST,NORTH,WEST};
int dir_x[4] = { 1,0,-1,0 };
int dir_y[4] = { 0,1,0,-1 };
vector <vector <int> > map(101, vector<int>(101, 0));
int A, B;
int N, M;
bool flag;

typedef struct Robot 
{
	pair<int, int> coord;
	int dir;
}Robot;

void go(int cur, Robot r[], int idx, int cnt)
{
	int x = r[idx].coord.first;
	int y = r[idx].coord.second;
	if ((x > B) || (y > A) || (x <= 0) || (y <= 0))
	{
		flag = true;
		printf("Robot %d crashes into the wall\n",idx);
		return;
	}
	
	else if (cur == cnt)
	
	{
		flag = false;
		return;
	}
	else
	{
		map[x][y] = 0;
		switch (r[idx].dir)
		{
		case 'S':
			r[idx].coord.first += dir_x[SOUTH];
			r[idx].coord.second += dir_y[SOUTH];
			break;
		default:
			r[idx].coord.first += dir_x[r[idx].dir % 4];
			r[idx].coord.second += dir_y[r[idx].dir % 4];
		}
		x = r[idx].coord.first;
		y = r[idx].coord.second;
		if (map[x][y]!= 0 && map[x][y] != idx)
		{
			flag = true;
			printf("Robot %d crashes into robot %d\n", idx, map[x][y]);
			return;
		}
		map[r[idx].coord.first][r[idx].coord.second] = idx;
		go(cur + 1, r, idx, cnt);
	}
	
	return;
}

void user_order(Robot r[], int idx, char order, int cnt)
{
	if (order == 'F')
	{
		go(0, r, idx, cnt);
		return;
	}
	cnt %= 4;

	if (r[idx].dir == 'S')
	{
		r[idx].dir++;
	}
	
	r[idx].dir = (order == 'R' ? (r[idx].dir - cnt) % 4 : (r[idx].dir + cnt) % 4);

	switch (r[idx].dir)
	{
	case EAST:
		r[idx].dir = 'E';

		break;
	case WEST:
		r[idx].dir = 'W';
		break;
	case SOUTH:
		r[idx].dir = 'S';
		break;
	case NORTH:
		r[idx].dir = 'N';
		break;

	}
}

int main()
{
	scanf("%d %d %d %d", &A, &B, &N, &M);
	Robot * robot = new Robot[N+1];	

	for (int i = 1; i <= N; i++)
	{
		int x,y;
		char dir;
		scanf("%d %d %c", &y, &x,&dir);
		x = B - x + 1;
		pair <int, int> xy = make_pair(x, y);
		map[x][y] = i;
		robot[i].coord = xy;
		robot[i].dir = dir;

	}

	for (int i = 1; i <= M; i++)
	{
		int idx, cnt;
		char order;

		scanf("%d %c %d", &idx, &order, &cnt);
		user_order(robot, idx, order, cnt);
		if (flag)
			break;
	}
	if(!flag)
		printf("OK\n");

	return 0;
}