#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
enum {RED=1,GREEN,BLUE};
vector <vector <int> > map (1001, vector <int>(4, 0));

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		for(int j = 1 ; j <= 3 ; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	vector <vector<int> > house(N+1, vector<int> (4,0));

	house[1][RED] = map[1][RED];
	house[1][GREEN] = map[1][GREEN];
	house[1][BLUE] = map[1][BLUE];

	for (int i = 2; i <= N; i++)
	{
		house[i][RED] = min(house[i - 1][BLUE], house[i - 1][GREEN]) + map[i][RED];
		house[i][GREEN] = min(house[i - 1][RED], house[i - 1][BLUE]) + map[i][GREEN];
		house[i][BLUE] = min(house[i - 1][RED], house[i - 1][GREEN]) + map[i][BLUE];
	}
	
	printf("%d", *min_element(house[N].begin()+1, house[N].end()));

	return 0;
}