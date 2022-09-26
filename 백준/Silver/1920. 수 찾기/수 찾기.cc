
//1920 수찾기 
#include <cstdio>

#define MAX_SIZE 100001

int arr[MAX_SIZE] = { 0, };
int target[MAX_SIZE] = { 0, };

int N = 0, M = 0;

void qSort(int s, int e, int * data) {
	if (s >= e) return;
	int left = s - 1;
	int right = e + 1;
	int pivot = data[(left + right) >> 1];
	while (1) {
		while (data[++left] < pivot);
		while (data[--right] > pivot);
		if (left >= right) {
			break;
		}
		int tmp = data[left];
		data[left] = data[right];
		data[right] = tmp;
	}
	qSort(s, left-1, data);
	qSort(right + 1, e, data);
}

bool binarySearch(int s, int e, int * data, int targetData) {
	while (s < e) {
		int mid = (s + e) >> 1;
		if (data[mid] == targetData) {
			return true;
		}
		else {
			if (data[mid] < targetData) {
				s = mid + 1;
			}
			else {
				e = mid;
			}
		}
	}
	return false;

}

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%d", &arr[n]);
	}
	scanf("%d", &M);
	for (int m = 0; m < M; m++) {
		scanf("%d", &target[m]);
	}

	qSort(0, N-1, arr);
	for (int m = 0; m < M; m++) {
		if (binarySearch(0, N, arr, target[m]) == false) {
			printf("0\n");
		}
		else {
			printf("1\n");
		}
	}
	return 0;
}
