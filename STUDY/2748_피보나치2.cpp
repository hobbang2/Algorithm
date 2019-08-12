#include <cstdio>
#include <vector>

using namespace std;

unsigned long long fibo[92];

void getFiboValue(int N) {
	fibo[0] = 0;
	fibo[1] = 1;
	fibo[2] = 1;

	for (int idx = 3; idx <= N; idx++) {
		fibo[idx] = fibo[idx - 1] + fibo[idx - 2];
	}

}

int main() {
	int N =0;
	scanf("%d", &N);
	getFiboValue(N);
	printf("%llu\n", fibo[N]);

	return 0;
}