#include <cstdio>

enum { WHITE, BLUE };

int N;
int white, blue;
int paper[129][129];


void devidePaper(int w, int h ,int len) {
	int curColor = paper[w][h];
	for (int y = w; y < w + len; y++) {
		for (int x = h; x < h + len; x++) {
			if (curColor == paper[y][x]) {
				continue;
			}
			else {
				devidePaper(w, h, len / 2);
				devidePaper(w+len/2, h, len / 2);
				devidePaper(w, h+len/2, len / 2);
				devidePaper(w + len / 2, h + len / 2, len / 2);
				return;
			}
		}
	}
	if (curColor == WHITE) {
		white += 1;
	}
	else {
		blue += 1;
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
	printf("%d\n%d\n", white, blue);
	return 0;
}