#include <cstdio>

enum { WHITE, BLUE };
int N;
int video[65][65];


void devideArea(int w, int h ,int len) {
	int curColor = video[w][h];
	for (int y = w; y < w + len; y++) {
		for (int x = h; x < h + len; x++) {
			if (curColor == video[y][x]) {
				continue;
			}
			else {
                printf("(");
				devideArea(w, h, len / 2);
				devideArea(w+len/2, h, len / 2);
				devideArea(w, h+len/2, len / 2);
				devideArea(w + len / 2, h + len / 2, len / 2);
                printf(")");
				return;
			}
		}
	}
	if (curColor == WHITE) {
		printf("%d", WHITE);
	}
	else {
		printf("%d", BLUE);
	}
}


int main() {

	scanf("%d", &N);
	for (int h = 0; h < N; h++) {
		for (int w = 0; w < N; w++) {
			scanf("%1d", &video[w][h]);
		}
	}
	devideArea(0, 0, N);
	return 0;
}