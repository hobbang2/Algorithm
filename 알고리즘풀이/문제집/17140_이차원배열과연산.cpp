#include <cstdio>
#include <vector>
#include <utility>
#include <queue>

#define pii pair<int,int>

using namespace std;

int map[101][101];

priority_queue <pii, vector<pii >, greater <pii > > makePQ(vector <int> & freq) {
	priority_queue <pii, vector<pii >, greater <pii > > curPQ;
	for (int idx = 1; idx < 101; idx++) {
		if (freq[idx] == 0) {
			continue;
		}
		pair <int, int> curPair(freq[idx], idx);
		curPQ.push(curPair);
	}
	return curPQ;
}

vector <int> makeNewLine(priority_queue <pii, vector<pii >, greater <pii > > & pq) {
	vector <int> newLine;
	while (pq.empty() == false)
	{
		pii curPair = pq.top(); pq.pop();
		newLine.push_back(curPair.second);
		newLine.push_back(curPair.first);
	}
	return newLine;

}

// 열의 수 ,, col! col이 바뀌어야 한다. 
void Rcal(int & row, int & col) {
	int maxSize = -1;
	for (int y = 1; y <= row; y++) {
		vector <int> freq(101, 0);
		for (int x = 1; x <= col; x++) {
			int curIdx = map[y][x];
			if (curIdx == 0) {
				continue;
			}
			freq[curIdx] += 1;
		}

		priority_queue <pii, vector<pii >, greater <pii > > curPQ = makePQ(freq);
		vector <int> newRow = makeNewLine(curPQ);
		int newSize = (int)newRow.size();
		newSize = (newSize < 100) ? newSize : 100;
		maxSize = (maxSize < newSize) ? newSize : maxSize;

		// 덮어쓰기 
		for (int idx = 0; idx < 100; idx++) {
			if (idx < newSize) {
				map[y][idx + 1] = newRow[idx];
			}
			else if (map[y][idx + 1] == 0) {
				continue;
			}
			else {
				map[y][idx + 1] = 0;
			}
		}
	}
	col = (maxSize < col) ? col : maxSize;
	// col = maxSize;
}

void Ccal(int & row, int & col) {
	int maxSize = -1;
	for (int x = 1; x <= col; x++) {
		vector <int> freq(101, 0);
		for (int y = 1; y <= row; y++) {
			int curIdx = map[y][x];
			if (curIdx == 0) {
				continue;
			}
			freq[curIdx] += 1;
		}
		priority_queue <pii, vector<pii >, greater <pii > > curPQ = makePQ(freq);
		vector <int> newCol = makeNewLine(curPQ);
		int newSize = (int)newCol.size();
		newSize = (newSize > 100) ? 100 : newSize;
		maxSize = (maxSize < newSize) ? newSize : maxSize;

		// 덮어쓰기 
		for (int idx = 0; idx < 100; idx++) {
			if (idx < newSize) {
				map[idx+1][x] = newCol[idx];
			}
			else if (map[idx+1][x] == 0) {
				continue;
			}
			else {
				map[idx+1][x] = 0;
			}
		}
	}
	row = (maxSize < row) ? row : maxSize;
}
int main() {
	int r = 0, c = 0, k = 0;
	int cnt = 0;
	scanf("%d %d %d", &r, &c, &k);
	int col = 3, row = 3;

	for (int y = 1; y <= row; y++) {
		for (int x = 1; x <= col; x++) {
			scanf("%d", &map[y][x]);
		}
	}

	while (map[r][c] != k) {
		if (cnt > 100) {
			cnt = -1;
			break;
		}
		if (row >= col) {
			Rcal(row, col);
		}
		else {
			Ccal(row, col);
		}

		cnt += 1;
	}
	printf("%d\n", cnt);
	return 0;
}