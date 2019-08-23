#include <cstdio>

int len[4002][4002] = { 0, };

int main() {
	char str1[4002] = { '0', };
	char str2[4002]= { '0', };
	int maxValue = 0;
	int i = 1;
	int j = 1;

	scanf("%s", str1+1);
	scanf("%s", str2+1);
	
	for (i = 1; str1[i] != '\0'; i++) {
		for (j = 1; str2[j] != '\0'; j++) {
			if (str1[i] == str2[j]) {
				len[i][j] = len[i - 1][j - 1] +1;
				maxValue = maxValue < len[i][j] ? len[i][j] : maxValue;
			}
			else {
				len[i][j] = 0;
			}
		}
	}
	printf("%d\n", maxValue);
	return 0;
}