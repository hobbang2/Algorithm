#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

#define pii pair<int,int>

typedef struct Student {
	int w, h;
	int idx;
	bool operator> (const Student & s) const {
		if ((h > s.h) && (w > s.w)) {
			return true;
		}
		return false;
	}

}Student;

int N;
vector <Student> stuVec;


int main() {
	int result[51] = { 0, };
	int tmpResult[51] = { 0, };
	cin >> N;
	stuVec.push_back({ 0,0,0 });
	
	for (int n = 1; n <= N; n++) {
		int w = 0, h = 0;
		cin >> w >> h;
		Student tmpS = { w,h,n };
		stuVec.push_back(tmpS);
	}

	sort(stuVec.begin() + 1, stuVec.end(), greater<Student>());

	for (int idx = 2; idx <= N; idx++) {
		if ((stuVec[idx - 1].w > stuVec[idx].w) &&
			(stuVec[idx - 1].h > stuVec[idx].h)) {
			if (tmpResult[idx - 1] == 0) {
				tmpResult[idx - 1] = idx - 1;
			}
			tmpResult[idx] = idx;
		}
		else {
			if (tmpResult[idx - 1] == 0) {
				tmpResult[idx - 1] = idx - 1;
			}
			tmpResult[idx] = tmpResult[idx - 1];
		}
	}

	for (int idx = 1; idx <= N; idx++) {
		result[stuVec[idx].idx] = tmpResult[idx];
	}

	for (int idx = 1; idx <= N; idx++) {
		cout << result[idx] << " ";
	}
	cout << "\n";
	return 0;
}
