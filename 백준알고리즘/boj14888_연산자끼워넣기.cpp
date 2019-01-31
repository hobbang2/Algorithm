/*
[입력] 
N : 수의 개수 (2<= N <= 11)
A1,A2,A3..,A100 (수열)
합이 N-1인 4개의 정수, +,-,x,/ 의 수 
[출력]
최댓값
최솟값
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
enum{PLUS,MINUS,MUL,DIV};

int N;
int seq[11];
int op[4];
int u_min = 1000000000;
int u_max = -1000000000;
//vector <int> min_max;


void cal(int cnt, int plus, int minus, int mul, int div,int result)
{
	if (cnt == N)
	{
		if (u_max < result)
			u_max = result;
		//min_max.push_back(result);
		if (u_min > result)
			u_min = result;
		return;
	}
	
	if (plus < op[PLUS])
		cal(cnt + 1, plus + 1, minus, mul, div, result + seq[cnt]);
	if (minus < op[MINUS])
		cal(cnt + 1, plus, minus + 1, mul, div, result - seq[cnt]);
	if (mul< op[MUL])
		cal(cnt + 1, plus , minus, mul+1, div, result * seq[cnt]);
	if (div < op[DIV])
		cal(cnt + 1, plus , minus, mul, div+1, result / seq[cnt]);
	return;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d",&seq[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &op[i]);
	}

	cal(1, 0, 0, 0, 0, seq[0]);
	
	//sort(min_max.begin(), min_max.end());
	//int len = min_max.size();

	//printf("%d\n%d", min_max[len-1], min_max[0]);
	printf("%d\n%d", u_max, u_min);
	return 0;
}
