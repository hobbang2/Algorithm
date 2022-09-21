#include <cstdio>

typedef struct Item {
	int w, v;
	Item() {
		w = 0, v = 0;
	}
}Item;

Item itemArr[101];
int knapsack[101][100001] = { 0, };

int getKnapsack(const int & N, const int & W,const Item arr[]) {
	for (int i = 1; i <= N; i++) {
		for (int w = 1; w <= W; w++) {
			if (arr[i].w > w) {
				knapsack[i][w] = knapsack[i - 1][w];
			}
			else {
				knapsack[i][w] = (knapsack[i - 1][w] > knapsack[i - 1][w - arr[i].w] + arr[i].v) ? knapsack[i - 1][w] : knapsack[i - 1][w - arr[i].w] + arr[i].v;
			}
		}
	}

	return knapsack[N][W];
}

int main() {
	int N = 0, K = 0;
	int answer = 0;
	scanf("%d %d", &N, &K);
	for (int n = 1; n <= N; n++) {
		scanf("%d %d", &itemArr[n].w, &itemArr[n].v);
	}
	answer = getKnapsack(N, K, itemArr);
	printf("%d\n", answer);
	return 0;
}