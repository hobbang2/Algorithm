#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

int N;
vector <int> adjGraph[11];
int people[11];
bool checkVill[11];
int answer = 10000;

void dfs(int curIdx,int & cnt,int & sum,int numOfVill,const vector <int> & curVill,vector <bool> & visited){
    int curSize =(int)adjGraph[curIdx].size();
    for(int nextIdx = 0; nextIdx < curSize; nextIdx++){
        int nextVill = adjGraph[curIdx][nextIdx];
        if((visited[nextVill]==false)&&(checkVill[curIdx] == checkVill[nextVill])){
			cnt += 1;
			sum += people[nextVill];
			visited[nextVill] = true;
			dfs(nextVill, cnt, sum, numOfVill, curVill, visited);
        }
    }
	return;
}

void chooseVillege(int idx, int cnt){
    if(idx > N + 1){
        return;
    }

    if(cnt == N){
        vector <int> leftNo;
        vector <int> rightNo;
        for(int no = 1; no <= N; no++){
            if(checkVill[no] == true){
                leftNo.push_back(no);
            }
            else{
                rightNo.push_back(no);
            }
        }

		if ((int)leftNo.size() == 0 || (int)rightNo.size() == 0) {
			return;
		}
		vector <bool> leftCheck(11, false);
		vector <bool> rightCheck(11, false);

		leftCheck[leftNo[0]] = true;
		rightCheck[rightNo[0]] = true;

		int leftCnt = 1, leftSum = people[leftNo[0]];
		int rightCnt = 1, rightSum = people[rightNo[0]];

		dfs(leftNo[0], leftCnt, leftSum, (int)leftNo.size(), leftNo, leftCheck);
		dfs(rightNo[0], rightCnt, rightSum, (int)rightNo.size(), rightNo, rightCheck);

		if ((leftCnt == (int)leftNo.size())&& (rightCnt == (int)rightNo.size())) {
			int diff = abs(leftSum - rightSum);
			answer = (answer > diff) ? diff : answer; 
		}
		return;
    }
    checkVill[idx]=true;
    chooseVillege(idx+1,cnt+1);
    checkVill[idx]=false;
    chooseVillege(idx+1,cnt+1);
}


int main(){
    scanf("%d",&N);
    for(int idx = 1 ; idx <= N ;idx++){
        scanf("%d",&people[idx]);
    }

    for(int idx = 1; idx <= N; idx++){
        int adjNum = 0;
        scanf("%d",&adjNum);
        for(int n = 1; n<= adjNum; n++){
            int connectVill = 0;
            scanf("%d",&connectVill);
            adjGraph[idx].push_back(connectVill);
        }
    }

    chooseVillege(1,0);
    (answer == 10000) ? printf("%d\n",-1):printf("%d\n",answer);
    return 0;
}