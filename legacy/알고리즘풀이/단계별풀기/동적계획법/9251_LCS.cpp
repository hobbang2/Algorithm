#include <cstdio>

int LCS[1001][1001] = { 0, };
char str[2][1001] = { 0, };

int myStrLen(const char * s) {
	int l = 0;
	while (*s++) {
		l++;
	}
	return l;
}

int getLCS() {
	int first = myStrLen(str[0]);
	int second = myStrLen(str[1]);
	for (int f = 1; f <= first; f++) {
		for (int s = 1; s <= second; s++) {
			// 마지막 문자가 같으면 이전 LCS maxLen +1
			if (str[0][f - 1] == str[1][s - 1]) {
				LCS[f][s] = LCS[f - 1][s - 1] + 1;
			}
			else {
				// 마지막 문자가 다르면 X문자열이나 Y문자열에서 하나 제외한 것 중 더 큰 것 고르자 
				LCS[f][s] = (LCS[f - 1][s] > LCS[f][s - 1]) ? (LCS[f - 1][s]) : (LCS[f][s-1]);
			}
		}
	}
	return LCS[first][second];
}


int main() {
	scanf("%s\n%s", str[0], str[1]);
	int answer = 0;
	answer = getLCS();
	printf("%d\n", answer);

	return 0;
}