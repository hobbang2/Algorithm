#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector <int> graph[1001];
vector <bool> isVisited_bfs(1001, false);
vector <bool> isVisited_dfs(1001, false);

void connectNode(int nodeNum1, int nodeNum2)
{
	graph[nodeNum1].push_back(nodeNum2);
	graph[nodeNum2].push_back(nodeNum1);
}

void bfs(int startNum)
{
	queue <int> que;
	isVisited_bfs[startNum] = true;
	que.push(startNum);

	while (!que.empty())
	{
		int nextNum = que.front(); que.pop();
		printf("%d ", nextNum);

		for (int i = 0; i < graph[nextNum].size(); i++)
		{
			int temp = graph[nextNum][i];
			if (!isVisited_bfs[temp])
			{
				que.push(temp);
				isVisited_bfs[temp] = true;
			}
		}
	}
}

void dfs(int nodeNum)
{
	if (isVisited_dfs[nodeNum]) return;
	isVisited_dfs[nodeNum] = true;
	printf("%d ", nodeNum);
	for (int i = 0; i < graph[nodeNum].size(); i++)
	{
		int next = graph[nodeNum][i];
		dfs(next);
	}

}


int main()
{
	int N, M, V;
	cin >> N >> M >> V;

	while (M--)
	{
		int startNode, endNode;
		cin >> startNode >> endNode;
		connectNode(startNode, endNode);
	}


	dfs(V);
	cout << "\n";
	bfs(V);

	return 0;
}