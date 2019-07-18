#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
enum { PATH, WALL, VIRUS, VISITED = -1};
int dir_x[4] = { 1,0,-1,0 };
int dir_y[4] = { 0,1,0,-1 };

int N, M;
int u_max;
vector< vector <int> > map(9, vector<int>(9, 0));
vector< vector <int> > cp_map(9, vector<int>(9, 0));

queue<int> que;

bool canGO(int x, int y)
{
	// out of range
	if (x <= 0 || y <= 0 || x > N || y > M)
		return false;
	if ((map[x][y] == WALL) || (map[x][y] == VIRUS))
		return false;
	return true;
}

void copyMap()
{
	copy(map.begin(), map.end(), cp_map.begin());
}

/*

void buidWall(int cnt, int east, int south, int west, int north,int x,int y)
{
	if (cnt == 3)
	{
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				if (map[i][j] == VIRUS)
					spread(i, j);
		int domain = checkDomain();
		if (u_max < domain)
			u_max = domain;
		copyMap();
	}


	buildWall(cnt + 1, east + 1, south, west, north);
		return;
}
*/
int checkDomain()
{
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (map[i][j] == PATH)
				cnt++;
		}
	}
	return cnt;
}

void spread(int x, int y)
{
	if (x <= 0 || y <= 0 || x > N || y > M)
		return;

	if (map[x][y] == VIRUS || map[x][y] == PATH)
	{
		map[x][y] = VIRUS;

		for (int i = 0; i < 4; i++)
		{
			int tmp_x = x;
			int tmp_y = y;

			tmp_x += dir_x[i];
			tmp_y += dir_y[i];

			if (!canGO(tmp_x, tmp_y))
				continue;
			spread(tmp_x, tmp_y);
		}
	}
}

void buildWall()
{
	int cnt = 0;
	int size = 0;
	int coord = 0;

	queue <int> que;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (map[i][j] == PATH)
			{
				map[i][j] = WALL;
				que.push(10 * i + j);
			}

	while (!que.empty())
	{
		if (cnt == 3)
		{
			for (int i = 1; i <= N; i++)
				for (int j = 1; j <= M; j++)
					if (map[i][j] == VIRUS)
						spread(i, j);
			int domain = checkDomain();
			if (u_max < domain)
				u_max = domain;
			copyMap();
		}

		size = que.size();
		int coord = que.front();
		int x = coord / 10;
		int y = coord % 10;

		while (size--)
		{
			int tmp_x = x;
			int tmp_y = y;

			for (int i = 0; i < 4; i++)
			{
				tmp_x = x;
				tmp_y = y;

				tmp_x += dir_x[i];
				tmp_y += dir_y[i];

				if (tmp_x <= 0 || tmp_y <= 0 || tmp_x > N || tmp_y > M)
					return;

				map[tmp_x][tmp_y] = WALL;
				que.push(tmp_x * 10 + tmp_y);
				
			}

		}
		cnt++;
	}
}


int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	copyMap();

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if(map[i][j] == VIRUS)
				spread(i, j);
		}
	}

	printf("\n\n");
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			printf("%d", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}