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

    for(int i = 1; i < N; i++){
        for(int j = 1; j <= N;j++){
            if(i == j){
                continue;
            }
            if((stuVec[i].w < stuVec[j].w) && (stuVec[i].h < stuVec[j].h)){
                result[i]++;
            }
        }
    }

	for (int idx = 1; idx <= N; idx++) {
		cout << result[idx] + 1 << " ";
	}
	cout << "\n";
	return 0;
}
