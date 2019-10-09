#include <cstdio>
#include <vector>

using namespace std;

int dx[4] = { -2,-1,1,2 };
vector <int> building;

void cleanVec() {
	vector <int> empty;
	building.swap(empty);
}

// 함수 바꿀 때 return 값 좀 신경써 ㅠ_ㅠ 
int getViewOk(int curH,int curIdx) {
	int nextIdx = 0;
	int nextH = 0;
	int tmpAns = 0;
	int answer = 1000001;
	for(int x = 0; x < 4; x++){
		nextIdx = curIdx + dx[x];
		nextH = building[nextIdx];
		if (nextH >= curH) {
			return 0;
		}
		else {
			tmpAns = curH - nextH;
			answer = (tmpAns < answer) ? tmpAns : answer;
		}
	}
	return answer;
}

int main() {
	int tc = 1;
	int idx = 0;
	int num = 0;
	int n = 0;
	int curH = 0;
	int answer = 0;
	for (tc = 1; tc <= 10; tc++) {
		scanf("%d",&num);
		building.reserve(sizeof(int)*num);
		
		for (n = 1; n <= num; n++) {
			scanf("%d", &curH);
			building.push_back(curH);
		}

		for (idx = 2; idx < num-2; idx++) {
			curH = building[idx];
			answer += getViewOk(curH, idx);
		}

		printf("#%d %d\n", tc, answer);
		cleanVec();
		answer = 0;
	}

	return 0;
}