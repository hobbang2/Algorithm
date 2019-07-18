/**
상도의 나무재테크
----------------------------
부동산 투자로 억대의 돈을 번 상도
NxN 크기의 땅을 구매
봄 - 여름 - 가을 - 겨울
[ 가장 처음 모든 칸에 양분이 5만큼 들어있음 ]
M 개의 나무를 구매해 땅에 심음.
[ 가장 처음 나무는 모두 다른 땅에 심어져 있음]
* 봄 : 나무가 자신의 나이만큼 양분을 먹고 나이가 1증가, 한 칸에 여러개의 나무가 있다면 나이가 어린 나무부터 양분을 먹는다. 만약 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없다면 죽음
* 여름 : 봄에 죽은 나무가 양분으로 변함.
나무의 나이/2
* 가을 : 나무가 번식한다. 나이가 5의 배수여야하며, 인접한 8개의 칸에 나이가 1인 나무가 생긴다.
* 겨울 : S2D2가 땅을 돌아다니면서 땅에 양분을 추가한다. 각 칸에 추가되는 양분의 양은 입력으로 주어진다.
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
// 오름차순 정렬을 위한 함수 
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
	// 겨울에 추가될 양분
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
	// 초기 나무들의 위치
	for (int num = 0; num < M; num++)
	{
		int y,x,age;
		scanf("%d %d %d", &y, &x, &age);
		Tree tree = { y,x,age };
		//init_tree[num] = tree;
		cur_tree_q[cur].user_push(tree);
	}

	// 가장 어린 나무부터 들어있답니당.
	sort(cur_tree_q[cur].arr+cur_tree_q[cur].front,
		cur_tree_q[cur].arr + cur_tree_q[cur].back ,comp);

	// K년 동안 세월이 흐릅니다..
	while (K--)
	{
		die_tree_q.init_();
		parent_tree_q.init_();
		cur_tree_q[1 - cur].init_();
		// 지금은 봄이에요! 
		// 신생트리부터 양분을 줍시다 ^_^
		while (!new_tree_q.is_empty())
		{
			Tree cur_tree = new_tree_q.front_elem(); new_tree_q.user_pop();
			//int cur_y = cur_tree.m_y;
			//int cur_x = cur_tree.m_x;
			// tree 나이만큼 양분 먹습니다.
			if (map[cur_tree.m_y][cur_tree.m_x] >= cur_tree.m_age)
			{
				map[cur_tree.m_y][cur_tree.m_x] -= cur_tree.m_age;
				cur_tree.m_age++;
				cur_tree_q[1 - cur].user_push(cur_tree);
				/*
				// 나이가 5의 배수이면 번식하러 가즈아
				if (cur_tree.m_age % 5 == 0)
					parent_tree_q.user_push(cur_tree);
				else
					cur_tree_q[1 - cur].user_push(cur_tree);
					*/
			}
			// 못먹으면 죽음 
			else
			{
				die_tree_q.user_push(cur_tree);
			}
		}
		/*
		// 이미 있던 트리들 양분을 먹습니당.
		// 현재 tree에 들어있던 나무 수 만큼만 돌거에요
		int cur_tree_q_size = cur_tree_q[cur].user_size();
		// 현재 tree들 나이순으로 sorting
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

				// 나이가 5의 배수이면 번식하러 가즈아 
				if ((cur_tree.m_age % 5) == 0)
				{
					parent_tree_q.user_push(cur_tree);
				}
			}
			else {
				die_tree_q.user_push(cur_tree);
			}
		}

		// 이제 여름입니당 ! 
		// 죽은 나무들이 양분으로 변할 차례
		while (!die_tree_q.is_empty())
		{
			Tree cur_die = die_tree_q.front_elem(); die_tree_q.user_pop();
			map[cur_die.m_y][cur_die.m_x] += (cur_die.m_age / 2);
		}

		// 이제 가을입니다. 번식 ㄱㄱ 
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

		// 겨울이에요 양분추가합시다.
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