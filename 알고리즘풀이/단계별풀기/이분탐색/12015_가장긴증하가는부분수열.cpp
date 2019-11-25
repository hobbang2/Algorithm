#include <cstdio>

using namespace std;

int N;
int A[1000001];
int subSet[1000001];

int binarySearch(int start, int end,int target) {
	int ans = 0;
	int mid = 0;
	while (start < end) {
		mid = (start + end) >> 1;
		if (subSet[mid] > target) {
			end = mid-1;
		}
		else {
			start = mid + 1;
		}
	}
	return end;
}

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%d", &A[n]);
	}

	int size = 1;
	subSet[0] = A[0];
	for (int n = 1; n < N; n++) {
		if (subSet[size-1] < A[n]) {
			subSet[size++] = A[n];
		}
		else {
			int mid = binarySearch(0, size,A[n]);
			subSet[mid] = A[n];
		}
	}
	printf("%d\n", size);

	return 0;
}