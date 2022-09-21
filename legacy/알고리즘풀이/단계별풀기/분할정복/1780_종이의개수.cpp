#include <cstdio>

enum { MINUS = -1, ZERO, PLUS};

int N;
int minus, zero,plus;
int paper[2200][2200];

void devidePaper(int w, int h, int len) {
	int curColor = paper[w][h];
	for (int y = w; y < w + len; y++) {
		for (int x = h; x < h + len; x++) {
			if (curColor == paper[y][x]) {
				continue;
			}
			else {
				int nextLen = len / 3;
				devidePaper(w, h, nextLen);
				devidePaper(w + nextLen, h, nextLen);
				devidePaper(w + 2 * nextLen, h, nextLen);

				devidePaper(w, h + nextLen, nextLen);
				devidePaper(w + nextLen, h + nextLen, nextLen);
				devidePaper(w + 2 * nextLen, h + nextLen, nextLen);


				devidePaper(w, h + 2 * nextLen, nextLen);
				devidePaper(w + nextLen, h + 2 * nextLen, nextLen);
				devidePaper(w + 2 * nextLen, h + 2 * nextLen, nextLen);

				return;
			}
		}
	}
	if (curColor == MINUS) {
		minus += 1;
	}
	else if(curColor == ZERO) {
		zero += 1;
	}
	else {
		plus += 1;
	}
}


int main() {

	scanf("%d", &N);
	for (int h = 0; h < N; h++) {
		for (int w = 0; w < N; w++) {
			scanf("%d", &paper[w][h]);
		}
	}
	devidePaper(0, 0, N);
	printf("%d\n%d\n%d\n", minus,zero, plus);
	return 0;
}