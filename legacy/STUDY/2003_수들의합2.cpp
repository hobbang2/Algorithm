#include <cstdio>
#include <vector>

using namespace std;
int N,M;
int cnt;
int nums[10001];
int main() {
	scanf("%d %d", &N,&M);
	for (int idx = 0; idx < N; idx++) {
		scanf("%d", &nums[idx]);
	}

	for (int start = 0; start < N; start++) {
		int sum = nums[start]; 
		for (int next = start + 1; next <= N; next++) {
			if (sum == M) {
				cnt++;
				break;
			}
			else if (sum > M || next == N) {
				break;
			}
			else {
				sum += nums[next];
			}
			
		}
	}

	printf("%d\n", cnt);

	return 0;
}