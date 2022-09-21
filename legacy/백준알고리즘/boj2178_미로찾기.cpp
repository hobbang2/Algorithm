#include <iostream>
#include <queue>
#include <utility>

using namespace std;

enum{NONE,PATH,VISITED};
int dir_x[4] = { 1,0,-1,0 };
int dir_y[4] = { 0,1,0,-1 };

int maze[101][101] = { 0, };
int M, N;

int bfs_find_path(int x, int y)
{
	int cnt = 0;

	queue<pair<int, int> > Q;
	pair<int, int> p(x, y);
	
	Q.push(p);

	while (!Q.empty())
	{
		int size = Q.size();
		while (size--)
		{
			pair<int, int> atom = Q.front();
			Q.pop();
			

			if ((atom.first == N) && (atom.second == M))
				return cnt+1;

			for (int i = 0; i < 4; i++)
			{
				pair<int,int> tmp = atom;
				
				tmp.first += dir_x[i];
				tmp.second += dir_y[i];
				
				int tmp_x = tmp.first;
				int tmp_y = tmp.second;

				if (tmp_x < 1 || tmp_y < 1 || tmp_x > N || tmp_y > M)
					continue;
				else if (maze[tmp_x][tmp_y] != PATH)
					continue;
				else
				{
					Q.push(tmp);
					maze[atom.first][atom.second] = VISITED;

				}
			}
		}
		cnt++;

	}
	return cnt;
}

/*
void dfs_find_path(int x, int y)
{
	if (x < 1 || y < 1 || x > N || y > M)
		return;

	if (maze[x][y] != PATH)     
		return;
	
	if ((x == N) && (y == M))
		return;

	maze[x][y] = VISITED;
	cnt++;
	int tmp_x, tmp_y;
	for (int i = 0; i < 4; i++)
	{
		tmp_x = x;
		tmp_y = y;
		
		tmp_x += dir_x[i];
		tmp_y += dir_y[i];
		dfs_find_path(tmp_x, tmp_y);
	}
}
*/
int main()
{
	scanf("%d", &N);
	fflush(stdin);
	scanf("%d", &M);

	printf("%d\n%d\n", N,M);
	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < M + 1; j++)
			scanf("%1d", &maze[i][j]);

	printf("%d\n", bfs_find_path(1, 1));

	return 0;
}
