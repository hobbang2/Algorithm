#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int N;
int result;

// ����� ũ��, �� ���� ����� �� 
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
	// ����� ��ġ�� ���ŵǾ��� �� true
	bool is_update = true;
	
	// ����� ��ġ�� ���ŵǴ� ���� 
	while (is_update)
	{
		is_update = false;
		// ����� ��ġ�� �� �� ���ŵǸ� �湮���� ���Ӱ� 
		bool is_visited[22][22] = { false, };
		// �� �� ���� �� ���� queue�� ����ô�.
		queue <Fish> q;
		// ���� ����� ��ġ�� �湮�ߴٰ� ǥ�� ���� + �� queue�� �����ô�.
		is_visited[shark.y][shark.x] = true;
		q.push(shark);
		// ��ǥ ���� 
		Fish candy;
		candy.y = 22, candy.time = -1;
		while (!q.empty())
		{
			// ���� �� ������� ���ô�.
			Fish cur_shark = q.front(); q.pop();

			// ���࿡ candy�� ã�������� ? queue �Ⱥ��� �� . �ֳ� ? queue�� candy�� ã�� ���ѰŴϱ� 
			// �ð� �񱳰� ��-�� ! 
			if (candy.time != -1 && candy.time < cur_shark.time)
			{
				break;
			}
			// ���࿡ ���� ��ġ�� ����Ⱑ �Ʊ���� �۴ٸ� ? ��ġ update !
			if (map[cur_shark.y][cur_shark.x] < shark_size && map[cur_shark.y][cur_shark.x] != 0)
			{
				is_update = true;
				// �� ����Ⱑ ������ ������ �ߴ� �� ���� �� ���ʿ� ������ ? candy ����
				if (cur_shark.y < candy.y || (cur_shark.y == candy.y && cur_shark.x < candy.x))
				{
					candy = cur_shark;
				}
			}
			// ���� ��ġ���� 4���� Ž���մϴ�.
			for (int d = 0; d < 4; d++)
			{
				Fish next; 
				next.time = cur_shark.time + 1;
				next.x = cur_shark.x + dir[d][0];
				next.y = cur_shark.y + dir[d][1];
				if (!isMap(next.y, next.x))
					continue;
				// ���� �� �̵��� ��ġ�� �湮���� �ʾҰ� �̵��� �� ������ queue �� ����
				else if (is_visited[next.y][next.x] == false && map[next.y][next.x] <= shark_size)
				{
					//��ȴٰ� ǥ���ϰ� 
					is_visited[next.y][next.x] = true;
					q.push(next);
				}
			}
		}
		// ���̸� ã�Ҵٸ� 
		if (is_update)
		{
			// �Ʊ���� ���� candy�� �ִ� ������ ����
			shark = candy;
			shark_eat++;
			// �� �ڱ� ��ġ��ŭ ����� �Ծ����� ũ�Ⱑ Ŀ����. 
			if (shark_eat == shark_size)
			{
				shark_size++;
				shark_eat = 0;
			}
			// �� �Ծ�ġ������ 0
			map[shark.y][shark.x] = 0;
		}

	}
}

int main()
{
	Fish shark = { 0,0,0 };
	scanf("%d", &N);

	// ���� ����� ��ġ'��' 
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
