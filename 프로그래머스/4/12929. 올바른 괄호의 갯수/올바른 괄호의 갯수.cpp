#include <string>
#include <vector>
#include <stack>
#include <set>

using namespace std;
int answer = 0;
set <string> emblaceSet;

int dfs(int open, int close, const int & MAX_N){
    
    if(open == MAX_N){
        return 1;
    }
    else if( open < close){
        return 0;
    }
    int cnt = 0;
    cnt += dfs(open + 1, close, MAX_N);
    cnt += dfs(open, close + 1, MAX_N);
    return cnt;
}

string makeTargetStr(int n){
    string ret = "";
    for(int idx = 0; idx < n ; ++idx){
        ret += "()";
    }
    return ret;
}

int dp[20] = {1,};

int dpSolution(int n){
    dp[0] = 1; dp[1] = 1; dp[2] = 2; dp[3] = 5;
    
    if(n > 3){
        for(int targetIdx = 4; targetIdx <= n; ++targetIdx){
            for(int secondIdx = 0 ; secondIdx < targetIdx; ++secondIdx){
                dp[targetIdx] += (dp[secondIdx] * dp[targetIdx -1 - secondIdx]);
                
            }
            
        }
    }
    return dp[n];
}


int solution(int n) {
    
    // return dfs(0, 0, n);
    return dpSolution(n);
    
}