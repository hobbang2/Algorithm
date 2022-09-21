#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

int dir_x[4] = { 0, 0, 1, -1 };
int dir_y[4] = { 1, -1, 0, 0 };
int map[101][101];
int chk_map[101][101];
int N;
int k;

void cpyMap()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			chk_map[i][j] = map[i][j];
}

bool desc(int a, int b)
{
	return a > b;
}

void dfsChk(int x, int y)
{
	chk_map[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dir_x[i];
		int next_y = y + dir_y[i];
		//주의하세용 !!!!!
		if (next_x < N && next_y < N && next_x >= 0 && next_y >= 0)
			if (chk_map[next_x][next_y])
				dfsChk(next_x, next_y);
	}
}

void bfs(int x, int y)
{
	int cnt = 0;
	pair <int, int> cord = { x,y };
	queue <int> que;
	int size = que.size();
}

int main()
{
	vector <int> vec;
	int max_h = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
			if (max_h < map[i][j])
				max_h = map[i][j];
		}


	for (k = 0; k <= max_h; k++)
	{
		int cnt = 0;
		cpyMap();

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				if (chk_map[i][j] <= k)
					chk_map[i][j] = 0;
			}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				if (chk_map[i][j])
				{
					cnt++;
					dfsChk(i, j);
				}
			}
		vec.push_back(cnt);
	}
	//sort(vec.begin(),vec.end(),desc);
	sort(vec.begin(), vec.end(), greater<int>());
	printf("%d", vec[0]);

	return 0;
}