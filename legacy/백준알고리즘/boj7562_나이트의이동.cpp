#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int u_move[8][2] = { {-2,-1},{-1,-2},{1,-2},{2,-1},
					{-2,1},{-1,2},{1,2},{2,1} };


typedef struct position
{
	int x;
	int y;
}position;


bool isCorrespond(position & present, position & orient)
{
	if ((present.x == orient.x) && (present.y == orient.y))
		return true;
	return false;
}

bool isInMap(position & present, int mapSize)
{
	if ((present.x < 0) || (present.y < 0))
		return false;
	if ((present.x >= mapSize) || (present.y >= mapSize))
		return false;
	return true;
}

int bfs(position & present, position & orient, int mapSize)
{
	int cnt = 0;
	queue <position> q_store;
	bool isVisited[300][300] = { 0 };

	isVisited[present.y][present.x] = true;
	q_store.push(present);

	while (!q_store.empty())
	{
		int queSize = q_store.size();
		while (queSize--)
		{
			position current = q_store.front(); q_store.pop();

			if (isCorrespond(current, orient))
			{
				return cnt;
			}

			for (int i = 0; i < 8; i++)
			{
				position temp = current;

				temp.y += u_move[i][0];
				temp.x += u_move[i][1];

				if ((!isVisited[temp.y][temp.x]) && (isInMap(temp, mapSize)))
				{
					isVisited[temp.y][temp.x] = true;
					q_store.push(temp);
				}
			}
		}
		cnt++;
	}
	return 0;
}

int main()
{
	int T, l;
	
	cin >> T ;
	
	while (T--)
	{
		position present;
		position orient;

		cin >> l;
		cin >> present.y >> present.x;
		cin >> orient.y >> orient.x;
		
		cout<<bfs(present, orient, l)<<"\n";
	}

	return 0;
}