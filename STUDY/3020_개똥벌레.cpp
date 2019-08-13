/*
개선방향 : 
1. 기수정렬  O(N)
2. lower bound 찾기 O(NlogN)
*/
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, H;

typedef struct caveInfo {
	int jongyu;
	int suck;

	caveInfo() {
		jongyu = 0;
		suck = 0;
	}
	
}caveInfo;

int main() {
	scanf("%d %d",&N,&H);
	vector <caveInfo> huddles(H + 1);
	vector <int> huddleCnt(H+1);
	

	for (int idx = 0; idx < N; idx++) {
		int curH = 0;
		scanf("%d", &curH);
		if (idx % 2 == 0) {
			huddles[curH].suck++;
		}
		else {
			curH = H - curH;
			huddles[curH+1].jongyu++;
		}
	}
	 
	for (int idx = 2; idx <= H; idx++) {
		huddles[H-idx+1].suck += huddles[H-idx+2].suck;
		huddles[idx].jongyu += huddles[idx-1].jongyu;
		huddleCnt[idx] = huddles[idx].suck + huddles[idx].jongyu;
	}

	for (int idx = 1; idx <= H; idx++) {
		huddleCnt[idx] = huddles[idx].suck + huddles[idx].jongyu;
	}
	 

	sort(huddleCnt.begin(), huddleCnt.end());

	int curValue = huddleCnt[1];
	int cnt = 1;
	for (int idx = 2; idx < (int)huddleCnt.size(); idx++) {
		if (curValue == huddleCnt[idx]) {
			cnt++;
		}
		else {
			break;
		}
	}

	printf("%d %d\n", curValue, cnt);
	return 0;
}