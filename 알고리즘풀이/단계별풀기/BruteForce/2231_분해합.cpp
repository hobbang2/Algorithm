#include <cstdio>

int N;
int digitNum = 0;
int digit[1000001];

void getDigit() {
	int tmpN = N;
	while (tmpN != 0) {
		digitNum++;
		tmpN /= 10;
	}
	return;
}
int findGenerator() {
	int result = N;
    // for(int curN = N - 54; curN < N; curN++)
	for (int curN = N - digitNum * 9; curN < N ; curN++) {
		int tmpN = curN;
		int tmpResult = curN;
		while (tmpN != 0) {
			tmpResult += (tmpN % 10);
			tmpN = (tmpN / 10);
		}
		if (tmpResult == N) {
			result = curN;
			break;
		}
	}
	return result;
}

int main() {
	scanf("%d", &N);
	getDigit();
	int answer = findGenerator();
	answer = (answer == N ? 0 : answer);
	printf("%d\n", answer);
	return 0;
}