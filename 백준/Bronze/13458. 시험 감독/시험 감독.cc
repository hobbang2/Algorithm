#include <cstdio>
#include <vector>

using namespace std;
int N;
int testPeople[1000000];
int B, C;
int main()
{
	long long allRequiredNum = 0;

	scanf("%d", &N);
	for (int roomNum = 0; roomNum < N; roomNum++)
	{
		int tmpNum = 0;
		scanf("%d", &tmpNum);
		testPeople[roomNum]=(tmpNum);
	}
	scanf("%d %d", &B, &C);

	for (int roomNum = 0; roomNum < N; roomNum++)
	{
		int people = testPeople[roomNum] - B;
		allRequiredNum++;
		if (people <= 0)
		{
			continue;
		}
		allRequiredNum += (people / C);
		allRequiredNum += (people % C == 0) ? 0 : 1;
	}

	printf("%lli\n", allRequiredNum);
	return 0;
}