#include <cstdio>

#define MAX_SEL 3

int N, M;
int result;
int numArr[101] = { 0, };
bool check[101] = { false, };

void selectCard(int idx, int cnt) {
	if (idx > N+1|| cnt > MAX_SEL) {
		return;
	}
	if (cnt == MAX_SEL) {
		int curResult = 0;
		for (int chkIdx = 1; chkIdx <= N; chkIdx++) {
			if (check[chkIdx] == true) {
				curResult += numArr[chkIdx];
			}
		}
		if ((curResult <= M) && (curResult > result)) {
			result = curResult;
		}
		return;
	}
	for (int curIdx = idx; curIdx <= N; curIdx++) {
		check[curIdx] = true;
		selectCard(curIdx + 1, cnt + 1);
		check[curIdx]=false;
	}
}

void selectCard_FOR(){
    for(int i = 1; i <= N; i++){
        for(int j = i + 1; j <= N; j++){
            for(int k = j+1; k <=N;k++){
                int tmp = numArr[i]+numArr[j]+numArr[k];
                if(tmp <= M && tmp > result){
                    result = tmp;
                }
            }
        }
    }
}


int main() {
	scanf("%d %d", &N, &M);
	for (int n = 1; n <= N; n++) {
		scanf("%d", &numArr[n]);
	}
	selectCard(1, 0);
	printf("%d\n", result);
	return 0;
}