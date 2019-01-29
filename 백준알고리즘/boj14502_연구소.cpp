#include <iostream>
#include <vector>
#include <queue>

using namespace std;
enum { PATH, WALL, VIRUS, VISITED = -1, OCCUPY = 7 };

int dir_x[4] = { 1,-1,0,0 };
int dir_y[4] = { 0,0,1,-1 };

int N, M;
vector< vector <int> > map(9, vector<int>(9, 0));
queue<int> que;

bool canGO(int x, int y)
{
	// out of range
	if (x <= 0 || y <= 0 || x > N || y > M)
		return false;
	if ((map[x][y] == WALL) || (map[x][y] == OCCUPY))
		return false;
	return true;
}

void buildWall(int x, int y)
{
	int cnt = 0;

	map[x][y] = VISITED;
	que.push(10 * x + y);
	
	while (!que.empty() || cnt != 3)
	{
		int size = que.size();
		int coord = que.front();

		int tmp_x = coord / 10;
		int tmp_y = coord % 10;


	}
}

int checkDomain()
{
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			if (map[i][j] == PATH)
				cnt++;
		}
	}
	return cnt;
}

void spread(int x, int y)
{
	if (!canGO(x, y)) return;

	map[x][y] = OCCUPY;

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

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
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