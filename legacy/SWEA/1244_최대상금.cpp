#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

vector <int> bitFlag;
vector <pair <int, int> > flagSet;
bool check[1000001][11];
void cleaner() {
	vector <int> empty;
	vector <pair <int, int > > emptyS;
	bitFlag.swap(empty);
	flagSet.swap(emptyS);
	memset(check, false, sizeof(flagSet));
}

void  makePairSet(int numS) {
	int left = -1, right = -1;
	do {
		left = -1, right = -1;
		for (int n = 0; n < numS; n++) {
			if (bitFlag[n] == 1) {
				(left == -1) ? (left = n) : (right = n);
			}
		}
		flagSet.push_back(make_pair(left, right));
	} while (next_permutation(bitFlag.begin(), bitFlag.end()));
}

int calReward(string num) {
	int mul = 1;
	int reward = 0;
	for (int n = (int)num.size() - 1; n >= 0; n--) {
		reward += (num[n] - '0')*mul;
		mul *= 10;
	}
	return reward;
}

void findAnsFOR(int & answer, string origin, int exc) {
	queue <string> possibleNum;
	int depth = 0;
	possibleNum.push(origin);
	while (possibleNum.empty() == false) {
		if (depth == exc) {
			break;
		}
		depth += 1;
		int qSize = (int)possibleNum.size();
		for (int q = 0; q < qSize; q++) {
			string curNum = possibleNum.front(); possibleNum.pop();
			for (int i = 0; i < (int)origin.size() -1; i++) {
				for (int j = i + 1; j < (int)origin.size(); j++) {
					string tmpNum = curNum;
					swap(tmpNum[i], tmpNum[j]);
					int tmpNumInt = stoi(tmpNum);
					if (check[tmpNumInt][depth] == false) {
						check[tmpNumInt][depth] = true;
						possibleNum.push(tmpNum);
						if (depth == exc) {
							answer = (answer < tmpNumInt) ? tmpNumInt : answer;
						}
					}
				}
			}
		}
	}
}

void findAns(int & answer, string origin, int exc) {
	queue <string> possibleNum;

	possibleNum.push(origin);
	int depth = 0;
	while (possibleNum.empty() == false) {
		if (depth == exc) {
			break;
		}
		depth += 1;
		int qSize = (int)possibleNum.size();
		for (int idx = 0; idx < qSize; idx++) {
			string tmpNum = possibleNum.front(); possibleNum.pop();
			for (int p = 0; p < (int)flagSet.size(); p++) {
				string curNum = tmpNum;
				int left = flagSet[p].first, right = flagSet[p].second;
				swap(curNum[left], curNum[right]);
				if (check[stoi(curNum)][depth] == false) {
					check[stoi(curNum)][depth] = true;
					possibleNum.push(curNum);
					if (depth == exc) {
						int tmpReward = calReward(curNum);
						answer = (answer < tmpReward) ? (tmpReward) : (answer);
					}
				}

			}
		}
	}
}

int main() {
	int T = 0, tc = 1;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++) {
		string numStr = "";
		int exchange = 0;
		cin >> numStr >> exchange;

		int numSize = (int)numStr.size();
		bitFlag.reserve(numSize * sizeof(int));

		int answer = -1;
		if (exchange == 0) {
			answer = calReward(numStr);
		}

		else {
			for (int s = 0; s < numSize - 2; s++) {
				bitFlag.push_back(0);
			}
			for (int s = 0; s < 2; s++) {
				bitFlag.push_back(1);
			}
			makePairSet(numSize);
			findAns(answer, numStr, exchange);
		}
		cout << "#" << tc << " " << answer << "\n";
		cleaner();
	}
}