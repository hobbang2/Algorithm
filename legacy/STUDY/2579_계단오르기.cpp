#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int num = 0;
	scanf("%d", &num);
	vector <int> score(num + 1, 0);
	vector <int> sumScore(num + 1, 0);

	for (int idx =1; idx <= num; idx++) {
		scanf("%d", &score[idx]);
	}

	sumScore[1] = score[1];
	sumScore[2] = score[1] + score[2];

	for (int idx = 3; idx <= num; idx++) {
		sumScore[idx] = max(sumScore[idx - 2] + score[idx], sumScore[idx - 3] + score[idx - 1] + score[idx]);
	}
	printf("%d\n", sumScore[num]);



	return 0;
}