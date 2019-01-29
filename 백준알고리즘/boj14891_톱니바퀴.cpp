#include <iostream>
using namespace std;

enum{ UNCLOCK=-1,CLOCK=1};
int wheel[5][8] = { 0, };
int tmp[5][8] = { 0, };

//�ð�������� ȸ��
void clock_spin(int num)
{
	int tmp = wheel[num][7];
	for (int i = 7; i > 0; i--)
		wheel[num][i] = wheel[num][i - 1];
	wheel[num][0] = tmp;
}

//�ݽð�������� ȸ��
void unclock_spin(int num)
{
	int tmp = wheel[num][0];
	for (int i = 0; i < 7; i++)
		wheel[num][i] = wheel[num][i + 1];
	wheel[num][7] = tmp;
}


void rec_move(int num, int dir,bool is_visited[])
{
	//base case 
	if (num <= 0 || num >= 5)
		return;
	if (is_visited[num])
		return;

	//��ȴ� ��Ϲ��� üũ 
	is_visited[num] = true;

	//��Ϲ����� ��ȣ���� ���̽� ������ 
	if (num == 1)
	{
		if (wheel[num][2] != wheel[num + 1][6])
		{
			rec_move(num + 1, -dir, is_visited);
		}

	}
	if (num == 2 || num == 3)
	{
		if (wheel[num][2] != wheel[num + 1][6])
			rec_move(num + 1, -dir, is_visited);
		if (wheel[num-1][2] != wheel[num][6])
			rec_move(num -1 , -dir, is_visited);

	}

	if (num == 4)
	{
		if (wheel[num][6] != wheel[num - 1][2])
		{
			rec_move(num - 1, -dir, is_visited);
		}

	}
	//������ �ݽð��ΰ� ? -> ������ unclock_spin �ƴϸ� clock_spin
	dir == UNCLOCK ? unclock_spin(num) : clock_spin(num);
	return;
}


int main()
{
	bool is_visited[5] = { false, };
	for (int i = 1; i < 5; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			scanf("%1d", &wheel[i][j]);
		}

	}
	int k;

	scanf("%d", &k);

	int num, dir;
	while (k--)
	{
		for (int i = 1; i < 5; i++)
			is_visited[i] = false;
		
		scanf("%d %d", &num, &dir);
		rec_move(num, dir, is_visited);
		
	}

	int sum = 0;
	int score = 1;
	for (int i = 1; i < 5; i++)
	{
		if (wheel[i][0] == 1)
		{
			sum += score;
		}
		score *= 2;
	}
	
	printf("%d", sum);
	return 0;
}