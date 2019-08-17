#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
	int N=0, L=0;
	scanf("%d %d", &N, &L);
	deque <pair<int,int> > dq_min;
	vector <pair<int,int> > A(N, pair<int,int> (0,0));
	vector <int> D(N, 0);

    // pair<int,int> : idx,value;
	for (int idx = 0; idx < N; idx++) {
		A[idx].first = idx;
		scanf("%d", &A[idx].second);
	}

	for (int idx = 0; idx < N; idx++) {
		if(idx-L+1 > 0){
			while((dq_min.empty() == false) && (dq_min.front().first < idx-L+1)){
				dq_min.pop_front();
			}
		}

		while((dq_min.empty()==false) &&(dq_min.back().second > A[idx].second)){
			dq_min.pop_back();
		}
		dq_min.push_back(A[idx]);
		D[idx] = dq_min.front().second;
	}


	for (int idx = 0; idx < N; idx++) {
		printf("%d ", D[idx]);
	}

	return 0;
}