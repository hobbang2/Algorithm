#include <cstdio>
#include <string>

using namespace std;

int N, M;
bool check[10] = { false ,};
void takeMofN(int idx, int cnt,string ans) {
	if (idx > N+1 || cnt > M) {
		return;
	}
	if (cnt == M) {
		for (int i = 0; i < (int)ans.size(); i++) {
			printf("%c ", ans[i]);
		}
		printf("\n");
		return;
	}
	for (int curIdx = 1; curIdx <=N; curIdx++) {
		if (check[curIdx] == true || curIdx == idx) {
			continue;
		}
		check[curIdx] = true;
		takeMofN(curIdx, cnt + 1,ans+to_string(curIdx));
		check[curIdx] = false;
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int num = 1; num <= N; num++) {
		check[num] = true;
		takeMofN(num, 1, to_string(num));
		check[num] = false;
	}
	return 0;
}