#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;



int main() {
	int N=0, L=0;
	scanf("%d %d", &N, &L);
	deque <int> deq;
	vector <int> A(N, 0);
	vector <int> D(N, 0);

	for (int idx = 0; idx < N; idx++) {
		scanf("%d", &A[idx]);
	}

	for (int idx = 0; idx < N; idx++) {
		if ((idx - L + 1 <=0)) {
			if (deq.size() == 0)
			{
				for (int i = 0; i <= idx; i++) {
					deq.push_back(A[i]);
				}
			}
			else {
				deq.push_back(A[idx]);
			}
			D[idx] = *min_element(deq.begin(), deq.end());
		}
		else {
			deq.pop_front();
			deq.push_back(A[idx]);
			D[idx] = *min_element(deq.begin(), deq.end());
		}
	}
	for (int idx = 0; idx < N; idx++) {
		printf("%d ", D[idx]);
	}

	return 0;
}