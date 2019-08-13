/*
개선방향 :
1. alphabet-'A'를 index로 사용하자. 
*/
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int getLeftIdx(int idx) {
	return idx * 2;
}

int getRightIdx(int idx) {
	return idx * 2 + 1;
}

int getRootIdx(int idx) {
	return idx / 2;
}

void preOrder(vector<char> & _tree, int idx) {
	if (idx >= _tree.size()||_tree[idx] == '.'|| _tree[idx] == 0) {
		return;
	}
	printf("%c", _tree[idx]);
	preOrder(_tree, getLeftIdx(idx));
	preOrder(_tree, getRightIdx(idx));
}

void midOrder(vector<char> & _tree, int idx) {
	if (idx >= _tree.size() || _tree[idx] == '.' || _tree[idx] == 0) {
		return;
	}
	midOrder(_tree, getLeftIdx(idx));
	printf("%c", _tree[idx]);
	midOrder(_tree, getRightIdx(idx));
}

int findIdx(vector <char> & _tree,char target) {
	for (int idx = 1; idx < (int)_tree.size(); idx++) {
		if (_tree[idx] == target) {
			return idx;
		}
	}
}

void aftOrder(vector<char> & _tree, int idx) {
	if (idx >= _tree.size() || _tree[idx] == '.' || _tree[idx] == 0) {
		return;
	}
	aftOrder(_tree, getLeftIdx(idx));
	aftOrder(_tree, getRightIdx(idx));
	printf("%c", _tree[idx]);
}
int main() {
	int N;
	char root, left, right;
	scanf("%d", &N);
	getchar();
	vector <char> tree(pow(2,N) + 1 , 0);
	for (int idx = 1; idx <= N; idx++) {
		scanf("%c %c %c", &root, &left, &right);
		getchar();
		if (idx == 1) {
			tree[idx] = root;
			tree[getLeftIdx(idx)] = left;
			tree[getRightIdx(idx)] = right;
		}
		else {
			int curRootIdx =findIdx(tree,root);
			tree[getLeftIdx(curRootIdx)] = left;
			tree[getRightIdx(curRootIdx)] = right;
		}
	}
	preOrder(tree,1);
	printf("\n");
	midOrder(tree, 1);
	printf("\n");
	aftOrder(tree, 1);
	printf("\n");

	return 0;
}