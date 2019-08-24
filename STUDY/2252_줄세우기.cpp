#include <cstdio>
#include <vector>
#include <queue>

using namespace std; 

int N, M;
int main() {
	scanf("%d %d", &N, &M);
	queue <int> students;
	vector < vector <int> >next(N + 1);
	vector <int> inOrder(N + 1,0);
	while (M--) {
		int target[2] = { 0, };
		scanf("%d %d", &target[0], &target[1]);
		next[target[0]].push_back(target[1]);
		inOrder[target[1]]++;
	}
	
	for (int idx = 1; idx < inOrder.size(); idx++) {
		if (inOrder[idx] == 0) {
			students.push(idx);
		}
	}
	
	while (!students.empty()) {
		int curInfo = students.front(); students.pop();
		printf("%d ", curInfo);
		for (int idx = 0; idx < next[curInfo].size(); idx++) {
			inOrder[next[curInfo][idx]]--;
			if (inOrder[next[curInfo][idx]] == 0) {
				students.push(next[curInfo][idx]);
			}
		}
	}

	return 0;
}