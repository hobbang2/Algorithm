#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

enum {PATH,WALL,VIRUS};
int dir_x[4] = { 1,-1,0,0 };
int dir_y[4] = { 0,0,1,-1 };

int N, M;
int max_scope = -1;

vector <vector <int> > map(9, vector <int>(9, 0));
vector <vector <int> > cp_map(9, vector<int>(9, 0));
queue <int> loc_virus;
queue <int> cp_loc_virus;

bool canGo(int x, int y)
{
	if (x <= 0 || y <= 0 || x > N || y > M)
		return false;
	else 
		return true;
}

void spread()
{
	copy(map.begin(), map.end(), cp_map.begin());
	cp_loc_virus = loc_virus;

	while (!cp_loc_virus.empty())
	{
		int tmp = cp_loc_virus.front();
		cp_loc_virus.pop();

		for (int i = 0; i < 4; i++)
		{
			int x = tmp / 17;
			int y = tmp % 17;

			x += dir_x[i];
			y += dir_y[i];

			if (canGo(x, y) && (cp_map[x][y] == PATH))
			{
				cp_map[x][y] = VIRUS;
				cp_loc_virus.push(17 * x + y);
			}
		}
	}
}

int cntScope()
{
	int cnt_scope = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (cp_map[i][j] == PATH)
				cnt_scope++;
	return cnt_scope;
}

void buildWall(int cnt, int curr)
{
	if (cnt == 3)
	{
		spread();
		cnt = cntScope();

		if (max_scope < cnt)
			max_scope = cnt;
	}
	else
	{
		for (int i = curr; i < N * M; i++)
		{
			int next_x = (i / M) + 1;
			int next_y = (i % M) + 1;

			if (map[next_x][next_y] == PATH)
			{
				map[next_x][next_y] = WALL;
				buildWall(cnt + 1, i + 1);
				map[next_x][next_y] = PATH;
			}
		}
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
			if (map[i][j] == VIRUS)
				loc_virus.push(i * 17 + j);
		}
	}
	buildWall(0, 0);
	printf("%d", max_scope);

}
