#include <cstdio>
#include <queue>
#include <cmath>
#define MAX_SIZE 52
using namespace std;

// mapsize, minimum, maximum
int N, L, R;
int map[MAX_SIZE][MAX_SIZE];
vector< vector <bool> > is_visited(MAX_SIZE, vector<bool> (MAX_SIZE, false));
// �α��̵��� �Ͼ���� check
bool moving_flag;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

typedef struct Coord
{
	int y, x;
}Coord;

// vector �ʱ�ȭ
void initVec(vector< vector <bool> > &swap)
{
	vector< vector <bool> > for_swap(MAX_SIZE, vector<bool>(MAX_SIZE, false));
	swap = for_swap;
}

bool isMap(int y, int x)
{
	if (y <= 0 || x <= 0 || y > N || x > N)
		return false;
	else
		return true;
}

// �α��̵�
void moving(int start_y, int start_x)
{
	int popular_sum = 0;
	Coord start = { start_y,start_x };
	queue <Coord> q;
	queue <Coord> tmp_q;

	is_visited[start.y][start.x] = true;
	q.push(start);
	tmp_q.push(start);

	while (!q.empty())
	{
		Coord cur = q.front(); q.pop();
		popular_sum += map[cur.y][cur.x];

		// 4���� ���鼭 �α��̵� �� �� �ִ� ���� �湮, tmp_queue �� ��ǥ����
		for (int d = 0; d < 4; d++)
		{
			Coord next = { 0,0 };
			next.y = cur.y + dir[d][0];
			next.x = cur.x + dir[d][1];
			// map �� �ƴϰų� �̹� �湮������ pass
			if ((!isMap(next.y, next.x)) || (is_visited[next.y][next.x] == true))
				continue;
			// �α� �� ���� ���ϱ� 
			int diff = abs(map[cur.y][cur.x] - map[next.y][next.x]);
			// ���ǿ� ������ push push ! 
			if ((L <= diff) && (diff <= R))
			{
				is_visited[next.y][next.x] = true;
				q.push(next);
				tmp_q.push(next);
			}
		}
	}

	int size = tmp_q.size();
	int popular_avg = popular_sum / size;

	// ������ �� ������ �ְ� �����ϹǷ� queue size �� 1�̸� ��ȿ���� ���� 
	if (tmp_q.size() != 1)
	{
		while ((!tmp_q.empty()))
		{
			// �α��̵� ���� 
			moving_flag = true;
			Coord tmp = tmp_q.front(); tmp_q.pop();
			map[tmp.y][tmp.x] = popular_avg;
		}


	}
}

int main()
{
	scanf("%d %d %d", &N, &L, &R);
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			scanf("%d", &map[y][x]);
		}
	}

	int cnt = -1;

	do
	{
		// �α��̵��� �� ���̶� �Ͼ���� cnt 
		moving_flag = false;
		for (int y = 1; y <= N; y++)
		{
			for (int x = 1; x <= N; x++)
			{
				if (!is_visited[y][x])
					moving(y, x);
			}
		}
		cnt++;
		initVec(is_visited);
	} while (moving_flag);

	printf("%d", cnt);


	return 0;
}