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
	// �ü��� ��ġ�� �Űܰ��鼭 ���� ���δ�. 
	// enemy�� empty �̰ų� idx �� �ִ�ũ�� M�� �ʰ��ϸ� return 
	if (idx > M)
		return;



	//�ü� 3���� ä������ return
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
			//������ �������� ���� �̵���Ų��. 
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
		�Ÿ��� D������ �� �߿� ���尡��� �� 
		������ ��� ���� ���� 
		������ ������ ���� �̵��ؾ��Ѵ�. 
		*/

		//���� �̵��Ѵ�. 
		//�ü��� �Ÿ��� D������ ���� ã�ƾ��ϴµ� ... 
		Coord candy = { -1,-1 };

	    // �ü��� �ִ� �ڸ��̸� ���� ���� 
		for (int bow = 1; bow <= M; bow++)
		{
			if (map[N + 1][bow] == 9)
			{
				// ���� ���鼭 �Ÿ� D�����̰� ���� ���ʿ� �ִ°� ã�´�. 
				int dist = 50;
				int enemy_idx = -1;

				for (int e = 0; e < enemy.size(); e++)
				{
					int tmp = abs(enemy[e].y - (N + 1)) + abs(enemy[e].x - bow);
					// ���� �� ���� ���̸� continue;
					if (tmp > D)
						continue;
					// distance ����
					// ���� ����� ��
					if (dist > tmp)
					{
						dist = tmp;
						candy.y = enemy[e].y;
						candy.x = enemy[e].x;
						die_s.insert(e);
					}
					// distance �� ������ �� ���ʿ� �ִ� ���� ���δ�. 
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
					// ���� �׿����ϱ� map���� ���� 
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
		//?? �ü� ���ո��� enemy �� ���� �ž� �ϴµ� ????? ^^?^? 
	}
}

int main()
{
	scanf("%d %d %d", &N, &M, &D);
	
	// map �޾ƿ��� 
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

	// �ü��� y = N+1 �� ��ġ�� 3�� ��ġ�ϸ鼭 ���� �� �ִ� ���� ���� �������. 
	// ( mC3 �� ����� ��)
	/*
	map ����
	index true ; 
	dfs
	index false;
	dfs
	map ���� ? 
	*/
	map[N + 1][1] = 9;
	killEnenemy(1, 0);
	printf("%d", result);
	return 0;
}