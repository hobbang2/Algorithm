#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

enum { PATH, WALL, VIRUS,BUILD, VISITED = -1, OCCUPY = 7 };

int dir_x[4] = { 1,-1,0,0 };
int dir_y[4] = { 0,0,1,-1 };

int N, M;
vector< vector <int> > map(9, vector<int>(9, 0));
vector<int> maxScope;
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


int checkDomain(vector<vector <int> > & vec)
{
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			if (vec[i][j] == PATH)
				cnt++;
		}
	}
	return cnt;
}

void spread(int x, int y,vector<vector <int> > &vec)
{
	if (!canGO(x,y)) return;
	
	vec[x][y] = OCCUPY;

	for (int i = 0; i < 4; i++)
	{
		int tmp_x = x;
		int tmp_y = y;

		tmp_x += dir_x[i];
		tmp_y += dir_y[i];

		if (!canGO(tmp_x, tmp_y))
			continue;
		spread(tmp_x, tmp_y,vec);

	}
}

void buildWall(int x, int y)
{
	if(!canGO(x,y))
		return;

	int cnt = 0;

	map[x][y] = VISITED;
	
	vector< vector<int> > cp_map(9, vector <int>(9,0)); 
	copy(map.begin(),map.end(),cp_map.begin());

	que.push(10 * x + y);
	
	while (cnt != 3)
	{
		
		int size = que.size();
		while(size--)
		{

			int coord = que.front();
			
			que.pop();

			int tmp_x = coord / 10;
			int tmp_y = coord % 10;
			if(!canGO(tmp_x,tmp_y))
					return;
			for(int i = 0 ; i<3;i++)
			{
				tmp_x += dir_x[i];
				tmp_y += dir_y[i];

				cp_map[tmp_x][tmp_y] = VISITED;
				que.push(tmp_x*10+tmp_y);
			}
		}
		cnt++;
	}

//	spread(1,1,cp_map);

	printf("\n\n");
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			printf("%d", cp_map[i][j]);
		}
		printf("\n");
	}

	maxScope.push_back(checkDomain(cp_map));
}

int main()
{
	int map_;
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			
			scanf("%d", &map_);
			map[i][j]=map_;
		}
	}

	for (int j=1; j<=M;j++)
	{
		buildWall(1,j);

	}
	cout<< maxScope.size();
//	printf("%d",*max_element(maxScope.begin(), maxScope.end()));

	/*
	printf("\n\n");
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
	*/

	return 0;
}
