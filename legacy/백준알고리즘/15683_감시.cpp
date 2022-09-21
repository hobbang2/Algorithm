#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_SIZE 9

using namespace std;

int rotation_times[6] = {0, 4,2,4,4,1 };
int N, M;
int cctv_size;
int result = 100;
bool is_visited[MAX_SIZE];
int map[MAX_SIZE][MAX_SIZE];

typedef struct CCTV
{
	int number;
	int y, x;
};

CCTV cctv_arr[MAX_SIZE];

bool isMap(int cur_y, int cur_x)
{
	if (cur_y <= 0 || cur_x <= 0 || cur_y > N || cur_x > M)
		return false;
	else
		return true;
}


int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

void mapCpy(int for_backup[][MAX_SIZE],int original[][MAX_SIZE])
{
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= M; x++)
		{
			for_backup[y][x] = original[y][x];

		}
	}
}

void startCCTV(CCTV & cur_cctv, int dir)
{
	int cur_y = cur_cctv.y;
	int cur_x = cur_cctv.x;

	dir = dir % 4;
	if (dir == 0)
	{
		for (int next_y = cur_y + 1; next_y <= N; next_y++)
		{
			if (map[next_y][cur_x] == 6)
				break;
			else if (map[next_y][cur_x] != 0)
				continue;
			else
				map[next_y][cur_x] = 9;
		}
	}
	else if (dir == 1)
	{
		for (int next_x = cur_x - 1; next_x > 0; next_x--)
		{
			if (map[cur_y][next_x] == 6)
				break;
			else if (map[cur_y][next_x] != 0)
				continue;
			else
				map[cur_y][next_x] = 9;
		}
	}
	else if (dir == 2)
	{
		for (int next_y = cur_y - 1; next_y > 0; next_y--)
		{
			if (map[next_y][cur_x] == 6)
				break;
			else if (map[next_y][cur_x] != 0)
				continue;
			else
				map[next_y][cur_x] = 9;
		}
	}

	else if (dir == 3)
	{
		for (int next_x = cur_x + 1; next_x <= M; next_x++)
		{
			if (map[cur_y][next_x] == 6)
				break;
			else if (map[cur_y][next_x] != 0)
				continue;
			else
				map[cur_y][next_x] = 9;
		}
	}
}


void dfs(int idx)
{

	if (idx == cctv_size)
	{
		int cnt = 0;
		for (int y = 1; y <= N; y++)
		{
			for (int x = 1; x <= M; x++)
			{
				printf("%d ", map[y][x]);
				if (map[y][x] == 0)
					cnt++;
			}
			printf("\n");

		}
		printf("\n");

		result = min(result, cnt);
		return;
	}
	// backup은 dfs 마다 새거여야합니당 
	int backup[MAX_SIZE][MAX_SIZE];

	int cctv_num = cctv_arr[idx].number;
	
	for (int rot_num = 0; rot_num < rotation_times[cctv_num]; rot_num++)
	{
		mapCpy(backup, map);

		if (cctv_num == 1)
		{
			startCCTV(cctv_arr[idx], rot_num);
		}
		else if (cctv_num == 2)
		{
			startCCTV(cctv_arr[idx], rot_num);
			startCCTV(cctv_arr[idx], rot_num+2);
		}
		else if (cctv_num == 3)
		{
			startCCTV(cctv_arr[idx], rot_num);
			startCCTV(cctv_arr[idx], rot_num + 1);
		}
		else if (cctv_num == 4)
		{
			startCCTV(cctv_arr[idx], rot_num);
			startCCTV(cctv_arr[idx], rot_num+1);
			startCCTV(cctv_arr[idx], rot_num + 2);
		}
		else if (cctv_num == 5)
		{
			startCCTV(cctv_arr[idx], rot_num);
			startCCTV(cctv_arr[idx], rot_num + 1);
			startCCTV(cctv_arr[idx], rot_num + 2);
			startCCTV(cctv_arr[idx], rot_num + 3);
		}
		dfs(idx + 1);
		mapCpy(map, backup);
	}
}

int main()
{
	scanf("%d %d",&N,&M);

	// map 받아오기
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= M; x++)
		{
			scanf("%d", &map[y][x]);
			if (map[y][x] > 0 && map[y][x] != 6)
			{
				CCTV cctv = { map[y][x],y,x};
				cctv_arr[cctv_size] = cctv;
				cctv_size++;
			}
		}
	}

	dfs(0);
	printf("%d", result);


	return 0;
}



// 5 번 감시카메라 ㄱㄱ 

/*
if (!cctv_vec[5].empty())
{
	for (int idx = 0; idx < cctv_vec.size(); idx++)
	{
		for (int d = 0; d < 4; d++)
		{
			while (1)
			{
				int next_y = cctv_vec[5][idx].y + dir[d][0];
				int next_x = cctv_vec[5][idx].x + dir[d][1];
				if (!isMap(next_y, next_x) || map[next_y][next_x] == 6)
					break;
				else
				{
					if (map[next_y][next_x] != 0)
						continue;
					else
					{
						map[next_y][next_x] = 9;
					}

				}
			}
		}
	}
}
*/