#include <cstdio>
#include <vector>

using namespace std;

int arr[100001];

int main() {
	int N = 0 , S = 0;
	int left = 0;
	int sum = 0;
	int cnt = 0; 

	scanf("%d %d", &N,&S);
	for (int idx = 0; idx < N; idx++) {
		scanf("%d", &arr[idx]);
	}

	int minCnt = 987654321;

	for (int idx = 0; idx < N; idx++) {
		sum += arr[idx];
		cnt++;
		if(sum >= S) {

			while (sum >= S)
			{
				sum -= arr[left++];
				cnt--;
			}
			if (minCnt > cnt+1) {
				minCnt = cnt+1;
			}
		}
	}
	minCnt = minCnt == 987654321 ? 0 : minCnt;
	printf("%d\n", minCnt);

	return 0;
}