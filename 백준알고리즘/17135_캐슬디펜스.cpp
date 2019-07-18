#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

#define MAX_SIZE 17
using namespace std;

int N, M, D;
int map[MAX_SIZE][MAX_SIZE];
int cpy_map[MAX_SIZE][MAX_SIZE];

int result = -1;
int tmp_kill = 0;

typedef struct Coord {
	int y, x;
}Coord;

vector <Coord> cpy_enemy;
vector <Coord> enemy;
set <int> die_s;

void swapMap(int dist[][MAX_SIZE], int src[][MAX_SIZE])
{
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= M; x++)
		{
			dist[y][x] = src[y][x];
		}
	}
}

void killEnenemy(int idx,int cnt)
{
	// 궁수의 위치를 옮겨가면서 적을 죽인다. 
	// enemy가 empty 이거나 idx 가 최대크기 M을 초과하면 return 
	if (idx > M)
		return;



	//궁수 3명이 채워지면 return
	if (cnt == 4)
	{
		set <int> ::iterator it;
		tmp_kill += die_s.size();
		for (it = die_s.begin(); it !=die_s.end(); it++)
		{
			enemy.erase(enemy.begin() + *it);
		}

		set <int> init_s;
		die_s = init_s;

		if (enemy.empty())
		{
			result = max(result, tmp_kill);
			tmp_kill = 0;
			enemy = cpy_enemy;
			return;
		}

		else
		{
			//공격이 끝났으면 적을 이동시킨다. 
			for (int e = 0; e < enemy.size();)
			{
				if ((enemy[e].y + 1) == (N + 1))
				{
					// map[enemy[e].y][enemy[e].x] = 0;
					enemy.erase(enemy.begin() + e);
				}
				else
				{
					enemy[e].y++;
					e++;
				}
			}

			if (enemy.empty())
			{
				result = max(result, tmp_kill);
				tmp_kill = 0;
				enemy = cpy_enemy;
				return;
			}
		}


	}

	

	
	else
	{
		/*
		거리가 D이하인 적 중에 가장가까운 적 
		여럿일 경우 가장 왼쪽 
		공격이 끝나면 적이 이동해야한다. 
		*/

		//적이 이동한다. 
		//궁수랑 거리가 D이하인 적을 찾아야하는데 ... 
		Coord candy = { -1,-1 };

	    // 궁수가 있는 자리이면 공격 ㄱㄱ 
		for (int bow = 1; bow <= M; bow++)
		{
			if (map[N + 1][bow] == 9)
			{
				// 적들 돌면서 거리 D이하이고 가장 왼쪽에 있는거 찾는다. 
				int dist = 50;
				int enemy_idx = -1;

				for (int e = 0; e < enemy.size(); e++)
				{
					int tmp = abs(enemy[e].y - (N + 1)) + abs(enemy[e].x - bow);
					// 죽일 수 없는 적이면 continue;
					if (tmp > D)
						continue;
					// distance 갱신
					// 가장 가까운 적
					if (dist > tmp)
					{
						dist = tmp;
						candy.y = enemy[e].y;
						candy.x = enemy[e].x;
						die_s.insert(e);
					}
					// distance 가 같으면 더 왼쪽에 있는 적을 죽인다. 
					else if (dist == tmp)
					{
						if (candy.x > enemy[e].x)
						{
							candy.y = enemy[e].y;
							candy.x = enemy[e].x;
							enemy_idx = e;
							die_s.insert(e);
						}
					}
				}
				/*
				if (enemy_idx >= 0)
				{
					tmp_kill++;
					// 적을 죽였으니까 map에서 제거 
					enemy.erase(enemy.begin() + enemy_idx);
					map[candy.y][candy.x] = 0;
				}
				*/
				
			}
		}
		
		map[N+1][idx] = 9;
		killEnenemy(idx + 1, cnt + 1);
		map[N + 1][idx] = 0;
		killEnenemy(idx, cnt + 1);
		//?? 궁수 조합마다 enemy 가 갱신 돼야 하는뎅 ????? ^^?^? 
	}
}

int main()
{
	scanf("%d %d %d", &N, &M, &D);
	
	// map 받아오기 
	// 0 
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= M; x++)
		{
			scanf("%d", &map[y][x]);
			if (map[y][x] == 1)
			{
				enemy.push_back({ y,x });
			}
		}
	}
	cpy_enemy = enemy;
	swapMap(cpy_map, map);

	// 궁수를 y = N+1 의 위치에 3명씩 배치하면서 죽일 수 있는 적의 수를 계산하자. 
	// ( mC3 의 경우의 수)
	/*
	map 저장
	index true ; 
	dfs
	index false;
	dfs
	map 복원 ? 
	*/
	map[N + 1][1] = 9;
	killEnenemy(1, 0);
	printf("%d", result);
	return 0;
}