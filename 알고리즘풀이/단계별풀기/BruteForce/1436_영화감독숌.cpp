#include <cstdio>

int main() {
	int N = 0;
	int answer[10002] = {0, 666,1666,2666,3666,4666,5666,6660 };

	scanf("%d", &N);

	 if (answer[N] == 0) {
		int target = 6661;
		int cnt = 7;
		for (; cnt < N;) {
			int tmp = target;
			while (tmp != 0) {
				if (tmp % 1000 == 666) {
					answer[++cnt] = target;
					break;
				}
				tmp /= 10;
			}
			target += 1;
		}
	}
	
		 printf("%d\n", answer[N]);
	 

	return 0;
}