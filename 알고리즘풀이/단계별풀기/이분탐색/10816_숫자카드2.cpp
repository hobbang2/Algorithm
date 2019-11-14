// 숫자카드2 
#include <cstdio>
#define MAX_SIZE 500000
int arr[MAX_SIZE] = { 0, };
int buf[MAX_SIZE] = { 0, };
int target[MAX_SIZE] = { 0, };

void mergeSort(int * data, int len) {
	if (len < 2) return;
	int mid = (len >> 1);
	int i = 0, j = mid, k = 0;

	mergeSort(data, mid);
	mergeSort(data + mid, len - mid);
	while ((i < mid) && (j < len)) {
		if (data[i] <= data[j]) {
			buf[k++] = data[i++];
		}
		else {
			buf[k++] = data[j++];
		}
	}

	while ((i < mid)) {
		buf[k++] = data[i++];
	}
	while ((j < len)) {
		buf[k++] = data[j++];
	}

	for (int idx = 0; idx < len; idx++) {
		data[idx] = buf[idx];
	}
}

void binarySearch(int s, int e,int * data, int targetNum,int & ans) {
	if (s >= e) {
		return;
	}
	int mid = (s + e) >> 1;
	if (data[mid] == targetNum) {
		ans += 1;
	}
	else {
		if (ans != 0) {
			return;
		}
	}
	binarySearch(s, mid, data, targetNum, ans);
	binarySearch(mid + 1, e, data, targetNum, ans);
}

int N = 0, M = 0;
int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%d", &arr[n]);
	}
	scanf("%d", &M);
	for (int m = 0; m < M; m++) {
		scanf("%d", &target[m]);
	}

	mergeSort(arr, N);
	printf("DEBUGGING \n");
	for (int n = 0; n < N; n++) {
		printf("%d ", arr[n]);
	}
	printf("\n");

	for (int m = 0; m < M; m++) {
		int curAns = 0;
		binarySearch(0, N, arr, target[m], curAns);
		printf("%d ", curAns);
	}
	printf("\n");
	return 0;
}