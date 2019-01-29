#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define LAND 1
#define SEA 0

int u_move[8][2] = { { 0, -1 },{ -1,-1 },{ -1,0 },{ 0,1 },
					{-1,1}, { 1,1 },{ 1,0 },{ 1,-1 } };


typedef struct position
{
	int x;
	int y;
	position() :x(0), y(0) {}
	position(int p_x, int p_y) :x(p_x), y(p_y) {}
}postion;

bool isInMap(position & pos)
{
	if (pos.x < 0 || pos.y < 0)
		return false;
	if (pos.x >= 50 || pos.y >= 50)
		return false;
	return true;
}

int landOrSea(vector<vector <int> >map,position & pos)
{
	return map[pos.x][pos.y] == LAND ?  LAND :  SEA;
	
}


void dfs(vector<vector<int>> map, bool isVisited[][50], position & pos)
{
	isVisited[pos.x][pos.y] = true;
	
	for (int i = 0; i < 8; i++)
	{
		position current = pos;

		current.x += u_move[i][0];
		current.y += u_move[i][1];
		
		if (!isInMap(current)) continue;

		if (!isVisited[current.x][current.y] && map[current.x][current.y])
		{
			dfs(map, isVisited, current);
		}

	}
	return;
}

int main()
{
	while (1)
	{
		int w, h;
		vector <vector<int>> map(50, vector<int>(50, 0));
		position start;

		cin >> w >> h;

		if ((w==0)&&(h==0)) break;

		for (int j = 0; j < h; j++)
		{
			for (int i = 0; i < w; i++)
				cin >> map[i][j];
		}

		bool isVisited[50][50] = { 0 };
		int cnt = 0;

		for (int j = 0; j < h; j++)
		{
			for (int i = 0; i < w; i++)
			{
				if (!isVisited[i][j] && map[i][j])
				{
					position cur(i, j);
					cnt++;
					dfs(map, isVisited, cur);
				}
			}
		}

		cout <<"answer : "<< cnt<<"\n";
	}

	return 0;
}