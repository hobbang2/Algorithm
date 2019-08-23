#include <cstdio>

using namespace std;

int len[1002][1002] = { 0, };
int idx[1002][1002][2] = { 0, };

int main() {
	char str1[1002] = { '0', };
	char str2[1002] = { '0', };
	char LCS[1002] = { '0', };
	int i = 1;
	int j = 1;

	int cnt = 0;

	scanf("%s", str1 + 1);
	scanf("%s", str2 + 1);

	for (i = 1; str1[i] != '\0'; i++) {
		for (j = 1; str2[j] != '\0'; j++) {
			if (str1[i] == str2[j]) {
				len[i][j] = len[i - 1][j - 1] + 1;
				idx[i][j][0] = i;
				idx[i][j][1] = j;

			}
			if (len[i - 1][j] > len[i][j]) {
				len[i][j] = len[i - 1][j];
				idx[i][j][0] = idx[i-1][j][0];
				idx[i][j][1] = idx[i-1][j][1];
			}
			if (len[i][j - 1] > len[i][j]) {
				len[i][j] = len[i][j - 1];
				idx[i][j][0] = idx[i][j-1][0];
				idx[i][j][1] = idx[i][j-1][1];
			}
		}
	}

	int maxLen = len[i - 1][j - 1];
	
	LCS[maxLen] = '\0';

	int curIidx = idx[i - 1][j - 1][0];
	int curJidx = idx[i - 1][j - 1][1];

	for (int l = maxLen-1; l >= 0; l--) {
		LCS[l] = str1[curIidx];
		// 왜 -1을 해주어야할까요 ㅠ_ㅠ ??? -> 한글자 앞에 올 인덱스를 봐야하니까 
		int nextIidx = idx[curIidx-1][curJidx-1][0];
		int nextJidx = idx[curIidx-1][curJidx-1][1];
		curIidx = nextIidx;
		curJidx = nextJidx;
	}

	printf("%d\n", len[i - 1][j - 1]);
	printf("%s\n", LCS);
	return 0;
}