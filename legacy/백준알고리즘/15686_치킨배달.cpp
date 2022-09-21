#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_SIZE 52

using namespace std;

typedef struct Info {
	int y, x;
}Info;

int result = 987654321;
int map[MAX_SIZE][MAX_SIZE];
vector <Info> chick_vec;
vector <Info> home_vec;


// 모든 가능한 조합을 검사할거에용 
void DFS(int cnt, int chick_num,int max_num,vector <bool> & remainChick)
{
	if (chick_num > chick_vec.size()) return;
	if (cnt == max_num)
	{
		int tmp = 0;
		for (int i = 0; i < home_vec.size(); i++)
		{
			int min_dist = 987654321;
			for (int j = 0; j < chick_vec.size(); j++)
			{
				// 남길 치킨집이면 최소거리 계산 
				if (remainChick[j])
				{
					int tmp_dist = abs(home_vec[i].y - chick_vec[j].y) + abs(home_vec[i].x - chick_vec[j].x);
					min_dist = min(min_dist, tmp_dist);
				}
			}
			tmp += min_dist;
		}
		result = min(result, tmp);
		return;
	}
	remainChick[chick_num] = true;
	DFS(cnt + 1, chick_num + 1, max_num, remainChick);
	remainChick[chick_num] = false;
	DFS(cnt , chick_num+1, max_num, remainChick);
}
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	getchar();

	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			scanf("%d", &map[y][x]);
			if (map[y][x] != 0)
			{
				map[y][x] == 1 ? home_vec.push_back({ y,x }) : chick_vec.push_back({ y,x });
			}
		}
	}
	vector <bool> remainChick(chick_vec.size(), false);
	DFS(0, 0,M,remainChick);
	printf("%d", result);
	return 0;
}