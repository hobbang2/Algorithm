#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
enum { ONE, TWO, THREE };



int main()
{
	int N;
	scanf("%d", &N);

	vector <int> dp(N + 1, 0);
	int cnt = 0;

	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= N; i++)
	{
		vector <int> tmp;
		if (i % 3 == 0)
			tmp.push_back(1 + dp[i / 3]);
		if (i % 2 == 0)
			tmp.push_back(1 + dp[i / 2]);
		tmp.push_back(1 + dp[i - 1]);

		dp[i] = *min_element(tmp.begin(), tmp.end());
	}

	printf("%d", dp[N]);
	return 0;
}