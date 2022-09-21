#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int N;
int result;

// 상어의 크기, 상어가 먹은 물고기 수 
int shark_size;
int shark_eat;

int map[22][22];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

typedef struct Fish {
	int y, x;
	int time;
}Fish;

vector <Fish> fish_vec;
vector <Fish> tmp_vec;

bool isMap(int y, int x)
{
	if (y <= 0 || x <= 0 || y > N || x > N)
		return false;
	else
		return true;
}
void babySharkGo(Fish & shark)
{
	// 상어의 위치가 갱신되었을 때 true
	bool is_update = true;
	
	// 상어의 위치가 갱신되는 동안 
	while (is_update)
	{
		is_update = false;
		// 상어의 위치가 한 번 갱신되면 방문판을 새롭게 
		bool is_visited[22][22] = { false, };
		// 한 판 마다 상어를 담을 queue를 만듭시다.
		queue <Fish> q;
		// 현재 상어의 위치에 방문했다고 표시 ㄱㄱ + 상어를 queue에 넣읍시다.
		is_visited[shark.y][shark.x] = true;
		q.push(shark);
		// 목표 먹이 
		Fish candy;
		candy.y = 22, candy.time = -1;
		while (!q.empty())
		{
			// 현재 상어가 어딨는지 봅시다.
			Fish cur_shark = q.front(); q.pop();

			// 만약에 candy가 찾아졌으면 ? queue 안봐도 됨 . 왜냐 ? queue는 candy를 찾기 위한거니까 
			// 시간 비교가 핵-심 ! 
			if (candy.time != -1 && candy.time < cur_shark.time)
			{
				break;
			}
			// 만약에 현재 위치의 물고기가 아기상어보다 작다면 ? 위치 update !
			if (map[cur_shark.y][cur_shark.x] < shark_size && map[cur_shark.y][cur_shark.x] != 0)
			{
				is_update = true;
				// 이 물고기가 예전에 먹으려 했던 것 보다 더 윗쪽에 있으면 ? candy 갱신
				if (cur_shark.y < candy.y || (cur_shark.y == candy.y && cur_shark.x < candy.x))
				{
					candy = cur_shark;
				}
			}
			// 현재 위치에서 4방향 탐색합니다.
			for (int d = 0; d < 4; d++)
			{
				Fish next; 
				next.time = cur_shark.time + 1;
				next.x = cur_shark.x + dir[d][0];
				next.y = cur_shark.y + dir[d][1];
				if (!isMap(next.y, next.x))
					continue;
				// 다음 상어가 이동할 위치가 방문되지 않았고 이동할 수 있으면 queue 로 ㄱㄱ
				else if (is_visited[next.y][next.x] == false && map[next.y][next.x] <= shark_size)
				{
					//들렸다고 표시하고 
					is_visited[next.y][next.x] = true;
					q.push(next);
				}
			}
		}
		// 먹이를 찾았다면 
		if (is_update)
		{
			// 아기상어는 이제 candy가 있는 곳으로 ㄱㄱ
			shark = candy;
			shark_eat++;
			// 상어가 자기 덩치만큼 물고기 먹었으면 크기가 커진다. 
			if (shark_eat == shark_size)
			{
				shark_size++;
				shark_eat = 0;
			}
			// 상어가 먹어치웠으니 0
			map[shark.y][shark.x] = 0;
		}

	}
}

int main()
{
	Fish shark = { 0,0,0 };
	scanf("%d", &N);

	// 상어랑 물고기 위치'ㅅ' 
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			scanf("%d", &map[y][x]);
			if (map[y][x] ==9)
			{
				shark = { y,x,0};
				shark_size = 2; shark_eat = 0;
				map[y][x] = 0;
			}
		}
	}
	babySharkGo(shark);
	printf("%d", shark.time);
	return 0;
}
