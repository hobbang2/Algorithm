//bfs 
//boj1963_52%
/* 문제설명
- 소수를 좋아하는 창영이
- 주어진 네자리 숫자에서 다른 숫자로 변경하려고 한다.
- 몇 번에 걸쳐서 바꿀 수 있을까 ?
** 조건
- 바꾸는 과정에서도 소수여야 한다.
*/

/* 해답
- 경우의 수가 많지 않고 최소 횟수를 찾아야한다 -> bfs
- 경우의 수 : max sqrt(10,4) <= 10000
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;


bool primeChk(int chkNum)
{
	if ((chkNum & 1) == 0)
		return (chkNum == 2);
	for (int i = 3; i * i <= chkNum; i++)
	{
		if ((chkNum % i) == 0)
			return false;
	}
	return true;
}

void getDigit(int storeNum[], int suggestNum)
{
	storeNum[0] = suggestNum / 1000;
	storeNum[1] = (suggestNum % 1000) / 100;
	storeNum[2] = (suggestNum % 100) / 10;	//storeNum[2] = (suggestNum % 1000)%100/10;
	storeNum[3] = suggestNum % 10;
}

int bfs(int storeNum[], int suggestNum, int orientNum)
{
	int cnt = 0;
	bool flag = false;
	vector <bool> isVisited(10000, false);
	queue <int> que;

	isVisited[suggestNum] = true;
	que.push(suggestNum);

	while (!que.empty())
	{
		int queSize = que.size();
		while (queSize--)
		{
			int nextNum = que.front(); que.pop();
			isVisited[nextNum] = true;

			if (nextNum == orientNum)
			{
				return cnt;
			}

			for (int i = 0; i < 4; i++)
			{
				getDigit(storeNum, nextNum);

				int j;
				for (i == 0 ? j = 1 : j = 0; j < 10; j++)
				{
					storeNum[i] = j;
					int changeNum = storeNum[0] * 1000 + storeNum[1] * 100 + storeNum[2] * 10 + storeNum[3];
					if (primeChk(changeNum) && (!isVisited[changeNum]))
					{
						que.push(changeNum);
					}
				}
			}
		}
		cnt++;
	}
	return -1;
}

int main()
{
	int storeNum[4];
	int testSize;
	int start, end;

	cin >> testSize;

	while (testSize--)
	{
		cin >> start >> end;
		int result = bfs(storeNum, start, end);
		(result == -1) ? cout << "Impossible" << "\n" : cout << result << "\n";
	}

	return 0;
}