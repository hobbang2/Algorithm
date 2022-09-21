/*
17135_캐슬디펜스
--------------------------
성을 향해 몰려오는 적을 잡는 턴 방식의 게임
게임판 : N x M, N+1에 성이 있다 !
궁수는 성이 있는 곳에만 한 칸에 한 명씩 총 3명 배치할 수 있음
각 턴마다 궁수는 적 하나를 공격할 수 있고, 모든 궁수는 ★동시에 공격
궁수가 공격하는 적은 거리가 D이하인 적 중 가장 가까운 적
이런 적이 여럿이면 가장 왼쪽에 있는 적을 공격 - x 좌표가 작은 순
같은 적이 여러 궁수에게 공격 당할 수 있고, 공격받은 적은 게임에서 제외
궁수의 공격이 끝나면 적이 이동, 적은 한 칸 이동 => 성이 있는 칸으로 이동하면 공격에서 제외됨
=> 모든 적이 격자판에서 제외되면 게임이 끝난다.
격자판의 상태가 주어졌을 때, 궁수의 공격으로 제거할 수 있는 적의 최대 수 ?
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
		// 적군이 담긴 set 을 복사
		set <Enemy> this_turn = s;
		// 궁수의 공격으로 죽은 적들
		set <Enemy> died_enemy;

		int this_turn_result = 0;

		// 게임 ㄱㄱ
		while (!this_turn.empty())
		{
			for (int i = 0; i < M; i++)
			{
				// 궁수가 배치되어있으면
				if (p[i])
				{
					cout << i << " ";
					Enemy ex_e = Enemy();
					// set 안의 적들에 대해서 사정거리 내에 있으면 죽인다.
					for (auto e : this_turn)
					{
						int dist = calDist(N, i, e);
						e.changeDist(dist);
						// 사정거리 내에 있고
						if (dist <= D)
						{
							// 거리가 가장 짧으면서 제일 왼쪽에 있는 적을 고른다.
							if (((dist == ex_e.getDist()) && (ex_e.getXY().second > e.getXY().second))
								|| (dist < ex_e.getDist()))
							{
								ex_e = e;
							}
						}
					}
					// 죽일 수 있는 적이 있으면 ㄱㄱ 
					if (ex_e.getXY().first != 999)
						died_enemy.insert(ex_e);
				}
			}

			this_turn_result+= died_enemy.size();
			
			// set은 정렬된 상태를 유지하기 위해서 원소의 값 변경이 쉽지 않음 
			// 새로운 set에다 다음 판까지 생존한 적을 넣어줌.
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
			
			// 확인용
			for (auto a : next_turn)
			{
				cout << "$ " << a.getXY().first << " " << a.getXY().second << " " << a.getDist() << endl;
			}
			cout << endl;

			// 생존한 적들과 함께 다음 판 ㄱㄱ 
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