/*
- N이 2인 경우를 생각해보면 
- 시작하는 수가 1일 때 그 다음 올 숫자는 0과 2
- 시작하는 수가 2일 때 그 다음 올 숫자는 1과 3 ... 
- N이 3인 경우를 생각해보면 
- 시작하는 수가 1일 때 그 다음 올 숫자는 0으로 시작하거나 2로 시작하는 두 자리 수 
- 시작하는 수가 2일 때 그 다음 올 숫자는 1으로 시작하거나 3로 시작하는 두 자리 수
...
*/

#include <cstdio>

#define MOD 1000000000

long long stairNum[101][11] = { 0, };

void initStair() {
	for (int n = 0; n <= 9; n++) {
		stairNum[1][n] = 1;
	}
	return;
}

void fillStairNum(const int & digit) {
	for (int d = 2; d <= digit; d++) {
		for (int n = 1; n <= 9; n++) {
			stairNum[d][n] = ((stairNum[d-1][n - 1])%MOD + (stairNum[d-1][n + 1])%MOD)%MOD;
		}
		stairNum[d][0] = stairNum[d - 1][1];
	}
	return;
}

long long getStairNum(const int & digit) {
	long long ret = 0;
	for (int n = 1; n <= 9; n++) {
		ret = (ret+ stairNum[digit][n])%MOD;
	}
	return ret % MOD;
}

int main() {
	int N = 0;
	long long answer = 0;
	scanf("%d", &N);
	initStair();
	fillStairNum(N);
	answer = getStairNum(N);
	printf("%lld\n", answer);
	return 0;
}