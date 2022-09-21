#include <cstdio>
#include <vector>

#define MAX_SIZE 52

enum {UP,DOWN};
using namespace std;

// R행 C열 T초
// 6~50,1000
int R, C, T;
int map[2][MAX_SIZE][MAX_SIZE];
int cleaner[2];

void initMap(int map[][MAX_SIZE])
{
	for (int r = 1 ;r <= R; r++)
	{
		for (int c = 1; c <= C; c++)
		{
			map[r][c] = 0;
		}
	}
}

bool isMap(int cur_r, int cur_c)
{
	if (cur_r <= 0 || cur_c <= 0 || cur_r > R || cur_c > C)
		return false;
	else
		return true;
}

int main()
{
	int cur = 0;
	scanf("%d %d %d", &R, &C, &T);
	for (int r = 1; r <= R; r++)
	{
		for (int c = 1; c <= C; c++)
		{
			scanf("%d", &map[cur][r][c]);
			if (map[cur][r][c] == -1)
			{
				map[1 - cur][r][c] = -1;
				if (cleaner[UP] == 0)
				{
					cleaner[UP] = r;
				}
				else
				{
					cleaner[DOWN] = r;
				}
			}
		}
	}

	int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

	while (T--)
	{
		//확산
		for (int r = 1; r <= R; r++)
		{
			for (int c = 1; c <= C; c++)
			{
				int cnt = 0;
				if (map[cur][r][c] > 0)
				{
					for (int d = 0; d < 4; d++)
					{
						int next_r = r + dir[d][0];
						int next_c = c + dir[d][1];
						if (isMap(next_r, next_c) && map[cur][next_r][next_c] >= 0)
						{
							map[1 - cur][next_r][next_c] += (map[cur][r][c] / 5);
							cnt++;
						}
						else
						{
							continue;
						}
					}
					map[cur][r][c] -= ((map[cur][r][c] / 5)*cnt);
					map[1 - cur][r][c] += map[cur][r][c];
					map[cur][r][c] = 0;
				}
			}
		}

		cur = 1 - cur;
		
		//청정
		// 상단 왼쪽
		for (int r = cleaner[UP]-1; r >1; r--)
		{
			map[cur][r][1] = map[cur][r-1][1];
		}
		//상단 윗쪽 
		for (int c = 1 ; c < C ; c++)
		{
			map[cur][1][c] = map[cur][1][c+1];
		}
		//상단 오른쪽
		for (int r = 1; r < cleaner[UP]; r++)
		{
			map[cur][r][C] = map[cur][r + 1][C];
		}
		//상단 아래쪽
		for (int c = C; c > 2; c --)
		{
			map[cur][cleaner[UP]][c] = map[cur][cleaner[UP]][c-1];
		}

		map[cur][cleaner[UP]][2] = 0;

		//청정
		// 하단 왼쪽
		for (int r = cleaner[DOWN] + 1; r < R;r++)
		{
			map[cur][r][1] = map[cur][r + 1][1];
		}
		// 하단 아래쪽 
		for (int c = 1; c < C; c++)
		{
			map[cur][R][c] = map[cur][R][c + 1];
		}
		//하단 오른쪽 
		for (int r = R; r > cleaner[DOWN]; r--)
		{
			map[cur][r][C] = map[cur][r - 1][C];
		}
		//하단 윗쪽 
		for (int c = C; c > 2; c--)
		{
			map[cur][cleaner[DOWN]][c] = map[cur][cleaner[DOWN]][c - 1];
		}
		map[cur][cleaner[DOWN]][2] = 0;
	}

	int result = 0;
	for (int r = 1; r <= R; r++)
	{
		for (int c = 1; c <= C; c++)
		{
			if (map[cur][r][c] > 0)
				result += map[cur][r][c];
		}
	}

	printf("%d", result);
	return 0;
}