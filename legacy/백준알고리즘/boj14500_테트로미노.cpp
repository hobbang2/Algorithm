#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int dir_x[4] = {-1,1,0,0};
int dir_y[4] = { 0,0,-1,1 };

vector<vector <int> >map(501, vector<int>(501, 0));
vector<vector <bool> >is_visited(501,vector<bool> (501,false));
vector<int> tmp;
int N, M;
int u_max = -1;

bool canGo(int x, int y)
{
	if (x <= 0 || y <= 0 || x > N || y > M) return false;
	else return true;
}

void specialTet(int x, int y)
{
	//ㅜ,ㅗ
	if ((x + 1 <= N) && (y + 2 <= M))
	{
		tmp.push_back(map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x + 1][y + 1]);
		tmp.push_back(map[x + 1][y] + map[x + 1][y + 1] + map[x + 1][y + 2] + map[x][y + 1]);
	}
	
	//ㅏ,ㅓ
	if ((x + 2 <= N) && (y + 1 <= M))
	{
		tmp.push_back(map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y + 1]);
		tmp.push_back(map[x][y + 1] + map[x + 1][y + 1] + map[x + 2][y + 1] + map[x + 1][y]);
	}

}

void connectTet(int cnt, int x, int y,int result)
{
	if (cnt == 4)
	{
		if (u_max < result)
			u_max = result;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			int tmp_x = x + dir_x[i];
			int tmp_y = y + dir_y[i];

			if ((canGo(tmp_x, tmp_y)) && (is_visited[tmp_x][tmp_y] == false))
			{
				is_visited[tmp_x][tmp_y] = true;
				connectTet(cnt + 1, tmp_x, tmp_y, result + map[tmp_x][tmp_y]);
				is_visited[tmp_x][tmp_y] = false;
			}
		}
	}
	return; 
}


int main() 
{
	scanf("%d%d", &N, &M);
	// 각 위치의 score를 저장합니다. 
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	// 전체 배열을 돌면서 dfs ㄱㄱ 
	for (int i = 0; i < N*M; i++)
	{
		int x = i / M + 1;
		int y = i % M + 1;

		is_visited[x][y] = true;
		connectTet(1, x, y,map[x][y]);
		is_visited[x][y] = false;

		specialTet(x, y);
	}

	tmp.push_back(u_max);
	u_max = *max_element(tmp.begin(), tmp.end());

	// 산 모양 돌면서 더 큰 값 없는지 계산 ㄱㄱ 
	printf("%d", u_max);

	return 0;
}