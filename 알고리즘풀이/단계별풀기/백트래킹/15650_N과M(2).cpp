#include <cstdio>
#include <string>

using namespace std;

int N, M;
bool check[10] = { false ,};
void takeMofN(int idx, int cnt) {
	if (idx > N+1 || cnt > M) {
		return;
	}
	if (cnt == M) {
		for (int n = 1; n <= N; n++) {
			if (check[n] == true) {
				printf("%d ", n);
			}
		}
		printf("\n");
		return;
	}
	for (int curIdx = idx; curIdx <=N; curIdx++) {
		check[curIdx] = true;
		takeMofN(curIdx+1, cnt + 1);
		check[curIdx] = false;
	}
}

void takeMofN(int idx, int cnt,string answer) {
	if (idx > N+1 || cnt > M) {
		return;
	}
	if (cnt == M) {
		for (int n = 0; n < M; n++) {
			printf("%c ", answer[n]);
		}
		printf("\n");
		return;
	}
	takeMofN(idx + 1, cnt + 1, answer + to_string(idx));
	takeMofN(idx + 1,cnt, answer);
}

int main() {
	scanf("%d %d", &N, &M);
	takeMofN(1, 0);
	return 0;
}