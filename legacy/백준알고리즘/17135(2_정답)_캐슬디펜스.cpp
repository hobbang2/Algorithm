/*
17135_ĳ�����潺
--------------------------
���� ���� �������� ���� ��� �� ����� ����
������ : N x M, N+1�� ���� �ִ� !
�ü��� ���� �ִ� ������ �� ĭ�� �� �� �� 3�� ��ġ�� �� ����
�� �ϸ��� �ü��� �� �ϳ��� ������ �� �ְ�, ��� �ü��� �ڵ��ÿ� ����
�ü��� �����ϴ� ���� �Ÿ��� D������ �� �� ���� ����� ��
�̷� ���� �����̸� ���� ���ʿ� �ִ� ���� ���� - x ��ǥ�� ���� ��
���� ���� ���� �ü����� ���� ���� �� �ְ�, ���ݹ��� ���� ���ӿ��� ����
�ü��� ������ ������ ���� �̵�, ���� �� ĭ �̵� => ���� �ִ� ĭ���� �̵��ϸ� ���ݿ��� ���ܵ�
=> ��� ���� �����ǿ��� ���ܵǸ� ������ ������.
�������� ���°� �־����� ��, �ü��� �������� ������ �� �ִ� ���� �ִ� �� ?
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int N, M, D;

class Enemy
{
private:
	int e_y;
	int e_x;
	int e_dist;

public:
	Enemy(int _y = 999, int _x = 999,int _dist = 987654321)
	{
		e_y = _y;
		e_x = _x;
		e_dist = _dist;
	}

	pair<int, int> getXY()
	{
		return make_pair(e_y, e_x);
	}
	
	void move()
	{
		++e_y;
	}


	void changeDist(int dist)
	{
		e_dist = dist;
	}

	int getDist()
	{
		return e_dist;
	}

	bool operator < (const Enemy & e) const {
		if (e_y == e.e_y) {
			return e_x > e.e_x;
		}
		return e_y > e.e_y;
	}

};

int calDist(int a_y, int a_x, Enemy & e)
{
	pair <int, int> e1 = e.getXY();
	return abs(e1.first - a_y) + abs(e1.second - a_x);
}

int max_result = -1;

void gameStart(set <Enemy> & s, vector <int> & p, int idx, int cnt)
{
	if (idx > M)
	{
		return;
	}
	if (cnt > 3)
	{
		return;
	}
	if (cnt == 3)
	{
		// ������ ��� set �� ����
		set <Enemy> this_turn = s;
		// �ü��� �������� ���� ����
		set <Enemy> died_enemy;

		int this_turn_result = 0;

		// ���� ����
		while (!this_turn.empty())
		{
			for (int i = 0; i < M; i++)
			{
				// �ü��� ��ġ�Ǿ�������
				if (p[i])
				{
					cout << i << " ";
					Enemy ex_e = Enemy();
					// set ���� ���鿡 ���ؼ� �����Ÿ� ���� ������ ���δ�.
					for (auto e : this_turn)
					{
						int dist = calDist(N, i, e);
						e.changeDist(dist);
						// �����Ÿ� ���� �ְ�
						if (dist <= D)
						{
							// �Ÿ��� ���� ª���鼭 ���� ���ʿ� �ִ� ���� ����.
							if (((dist == ex_e.getDist()) && (ex_e.getXY().second > e.getXY().second))
								|| (dist < ex_e.getDist()))
							{
								ex_e = e;
							}
						}
					}
					// ���� �� �ִ� ���� ������ ���� 
					if (ex_e.getXY().first != 999)
						died_enemy.insert(ex_e);
				}
			}

			this_turn_result+= died_enemy.size();
			
			// set�� ���ĵ� ���¸� �����ϱ� ���ؼ� ������ �� ������ ���� ���� 
			// ���ο� set���� ���� �Ǳ��� ������ ���� �־���.
			set <Enemy> next_turn;
			for (auto e : this_turn)
			{
			    if (died_enemy.find(e) == died_enemy.end())
				{
					e.move();
					if (e.getXY().first < N)
						next_turn.insert(e);
				}
			}
			
			// Ȯ�ο�
			for (auto a : next_turn)
			{
				cout << "$ " << a.getXY().first << " " << a.getXY().second << " " << a.getDist() << endl;
			}
			cout << endl;

			// ������ ����� �Բ� ���� �� ���� 
			this_turn = next_turn;
			died_enemy.clear();
		}
		max_result = (max_result < this_turn_result ? this_turn_result : max_result);
	}
	p[idx] = 1;
	gameStart(s, p, idx + 1, cnt + 1);
	p[idx] = 0;
	gameStart(s, p, idx + 1, cnt);
}

int main()
{
	set <Enemy> e_set;

	scanf("%d %d %d", &N, &M, &D);
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			int position = 0;
			scanf("%d", &position);
			if (position == 1)
			{
				e_set.insert(Enemy(y, x, 0));
			}
		}
	}

	vector <int> position(M+1, 0);
	gameStart(e_set, position, 0, 0);
	cout << max_result;
	getchar();

	return 0;
}