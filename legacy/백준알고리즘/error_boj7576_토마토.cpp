#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
enum{NONE=-1,TOMATO,WELL};
/*
정수 M,N // M 은 상자의 가로 칸 수 , N은 상자의 세로 칸 수 
하나의 상자에 저장된 토마토들의 정보 // 1 익은 토마토 0 익지 x -1 토마토없음
 */
int dir_x[4] = {1,-1,0,0};
int dir_y[4] = {0,0,1,-1};
int M,N;
int ** tomato;

int findWELL()
{
	bool flag = false;
	int days = 0;
	queue <int> que;

	//익었으면 시작한다. 
	for(int i = 0 ; i < N; i++)
	{
		for (int j = 0 ; j <M;j++)
				printf("%d %d",i,j);
		printf("\n");
				//if(tomato[i][j] == WELL)
	}
	printf("fasfs");
	while(!que.empty())
	{
		flag = true;
		int size = que.size();
		while(size--)
		{
			int atom = que.front();
			que.pop();
			int tmp_x = atom/10000000;
			int tmp_y = atom%10000000;

			for(int i = 0 ; i < 4 ; i ++)
			{
				int x = tmp_x;
				int y = tmp_y;

				x+= dir_x[i];
				y+= dir_y[i];
				
				if(x < 0 || y <0 || x >= M || y >= N)
					continue;
				if(tomato[x][y]!=TOMATO)
					continue;
				tomato[x][y] = WELL;
				que.push(10000000*x+y);
			}
		}
		days++;
	}

	for (int i= 0 ; i <N;i ++)
		for(int j = 0; j <M;j++)
			if(tomato[i][j]!=WELL)
				return -1;

	if(!flag) return 0;
	else return days;
}



int main()
{
	scanf("%d%d",&M,&N);
	int ** tomato = new int* [N];
	for (int i = 0 ; i < N; i++)
		tomato[i] = new int[M];
	
	for (int i =0; i <N;i++)
	{
		for(int j = 0 ; j < M ;j++)
		{
			scanf("%d",&tomato[i][j]);
		}
	}
	printf("%d %d",M,N);

printf("\n");

	for (int i =0; i <N;i++)
	{
		for(int j = 0 ; j < M ;j++)
		{
			printf("%d",tomato[i][j]);
		}
printf("\n");
	}
	cout<<findWELL();
	return 0;
}


