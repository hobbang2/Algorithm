/**
���� ��������ũ
----------------------------
�ε��� ���ڷ� ����� ���� �� ��
NxN ũ���� ���� ����
�� - ���� - ���� - �ܿ�
[ ���� ó�� ��� ĭ�� ����� 5��ŭ ������� ]
M ���� ������ ������ ���� ����.
[ ���� ó�� ������ ��� �ٸ� ���� �ɾ��� ����]
* �� : ������ �ڽ��� ���̸�ŭ ����� �԰� ���̰� 1����, �� ĭ�� �������� ������ �ִٸ� ���̰� � �������� ����� �Դ´�. ���� ���� ����� ������ �ڽ��� ���̸�ŭ ����� ���� �� ���ٸ� ����
* ���� : ���� ���� ������ ������� ����.
������ ����/2
* ���� : ������ �����Ѵ�. ���̰� 5�� ��������ϸ�, ������ 8���� ĭ�� ���̰� 1�� ������ �����.
* �ܿ� : S2D2�� ���� ���ƴٴϸ鼭 ���� ����� �߰��Ѵ�. �� ĭ�� �߰��Ǵ� ����� ���� �Է����� �־�����.
*/


#include <cstdio>
#include <algorithm>

#define MAX_SIZE 11
using namespace std;

int N, M, K;
int map[MAX_SIZE][MAX_SIZE];
int energy[MAX_SIZE][MAX_SIZE];


typedef struct Tree
{
	int m_y, m_x;
	int m_age;
}Tree;

class QUEUE
{
public:
	int front, back;
	Tree arr[684000];
	QUEUE()
	{
		front = 0; back = 0;
	}

	void init_()
	{
		front = 0; back = 0;
	}
	bool is_empty()
	{
		return (front == back);
	}
	Tree front_elem()
	{
		return arr[front];
	}
	void user_push(Tree & tree)
	{
		arr[back++] = tree;
	}
	void user_pop()
	{
		front++;
	}

	int user_size()
	{
		return back - front;
	}
};
// �������� ������ ���� �Լ� 
bool comp(Tree & a, Tree & b)
{
	return a.m_age < b.m_age;
}

bool isMap(int y, int x)
{
	if (y <= 0 || x <= 0 || y > N || x > N)
		return false;
	else
		return true;
}

Tree init_tree[100];
QUEUE cur_tree_q[2];
//QUEUE next_tree_q;
QUEUE parent_tree_q;
QUEUE die_tree_q;
QUEUE new_tree_q;


int main()
{
	scanf("%d %d %d", &N, &M, &K);
	// �ܿ￡ �߰��� ���
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			scanf("%d", &energy[y][x]);
			map[y][x] = 5;
		}
	}
	// cur = 0 , next = 1 toggle
	int cur = 0;
	// �ʱ� �������� ��ġ
	for (int num = 0; num < M; num++)
	{
		int y,x,age;
		scanf("%d %d %d", &y, &x, &age);
		Tree tree = { y,x,age };
		//init_tree[num] = tree;
		cur_tree_q[cur].user_push(tree);
	}

	// ���� � �������� ����ִ�ϴ�.
	sort(cur_tree_q[cur].arr+cur_tree_q[cur].front,
		cur_tree_q[cur].arr + cur_tree_q[cur].back ,comp);

	// K�� ���� ������ �帨�ϴ�..
	while (K--)
	{
		die_tree_q.init_();
		parent_tree_q.init_();
		cur_tree_q[1 - cur].init_();
		// ������ ���̿���! 
		// �Ż�Ʈ������ ����� �ݽô� ^_^
		while (!new_tree_q.is_empty())
		{
			Tree cur_tree = new_tree_q.front_elem(); new_tree_q.user_pop();
			//int cur_y = cur_tree.m_y;
			//int cur_x = cur_tree.m_x;
			// tree ���̸�ŭ ��� �Խ��ϴ�.
			if (map[cur_tree.m_y][cur_tree.m_x] >= cur_tree.m_age)
			{
				map[cur_tree.m_y][cur_tree.m_x] -= cur_tree.m_age;
				cur_tree.m_age++;
				cur_tree_q[1 - cur].user_push(cur_tree);
				/*
				// ���̰� 5�� ����̸� �����Ϸ� �����
				if (cur_tree.m_age % 5 == 0)
					parent_tree_q.user_push(cur_tree);
				else
					cur_tree_q[1 - cur].user_push(cur_tree);
					*/
			}
			// �������� ���� 
			else
			{
				die_tree_q.user_push(cur_tree);
			}
		}
		/*
		// �̹� �ִ� Ʈ���� ����� �Խ��ϴ�.
		// ���� tree�� ����ִ� ���� �� ��ŭ�� ���ſ���
		int cur_tree_q_size = cur_tree_q[cur].user_size();
		// ���� tree�� ���̼����� sorting
		sort(cur_tree_q[cur].arr + cur_tree_q[cur].front, cur_tree_q[cur].arr + cur_tree_q[cur].back, comp);
		*/
		while (!cur_tree_q[cur].is_empty())
		{
			Tree cur_tree = cur_tree_q[cur].front_elem(); cur_tree_q[cur].user_pop();
			//int cur_y = cur_tree.m_y;
			//int cur_x = cur_tree.m_x;
			if (map[cur_tree.m_y][cur_tree.m_x] >= cur_tree.m_age)
			{
				map[cur_tree.m_y][cur_tree.m_x] -= cur_tree.m_age;
				cur_tree.m_age++;
				cur_tree_q[1 - cur].user_push(cur_tree);

				// ���̰� 5�� ����̸� �����Ϸ� ����� 
				if ((cur_tree.m_age % 5) == 0)
				{
					parent_tree_q.user_push(cur_tree);
				}
			}
			else {
				die_tree_q.user_push(cur_tree);
			}
		}

		// ���� �����Դϴ� ! 
		// ���� �������� ������� ���� ����
		while (!die_tree_q.is_empty())
		{
			Tree cur_die = die_tree_q.front_elem(); die_tree_q.user_pop();
			map[cur_die.m_y][cur_die.m_x] += (cur_die.m_age / 2);
		}

		// ���� �����Դϴ�. ���� ���� 
		int dir[8][2] = { {0,1},{0,-1},{1,0},{-1,0},
						{1,-1},{-1,1},{1,1},{-1,-1} };
		new_tree_q.init_();
		while (!parent_tree_q.is_empty())
		{
			Tree cur_parent = parent_tree_q.front_elem(); parent_tree_q.user_pop();
			for (int d = 0; d < 8; d++)
			{
				Tree new_tree;

				new_tree.m_y = cur_parent.m_y + dir[d][0];
				new_tree.m_x = cur_parent.m_x + dir[d][1];
				new_tree.m_age = 1;
				if (!isMap(new_tree.m_y, new_tree.m_x))
					continue;
				new_tree_q.user_push(new_tree);
			}
		}

		// �ܿ��̿��� ����߰��սô�.
		for (int y = 1; y <= N; y++)
		{
			for (int x = 1; x <= N; x++)
			{
				map[y][x] += energy[y][x];
			}
		}

		cur = 1 - cur;
	}

	int live_tree = cur_tree_q[cur].user_size() + new_tree_q.user_size();
	printf("%d", live_tree);

	return 0;
}