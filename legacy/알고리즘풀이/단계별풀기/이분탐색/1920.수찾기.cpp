//1920 수찾기 
#include <cstdio>

#define MAX_SIZE 100001

int buf[MAX_SIZE] = { 0, };
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

void mergeSort(int * data, int len) {
	if (len < 2) {
		return;
	}
	int mid = (len >> 1);
	int i = 0, j = mid , k = 0;

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

	//mergeSort(arr, N);
	qSort(0, N-1, arr);
	printf("DEBUGGING : print arr elem\n");
	for (int n = 0; n < N; n++) {
		printf("%d ", arr[n]);
	}
	printf("\n");

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