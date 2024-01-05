#include <vector>
#include <utility>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
/*
일부 구역은 자동차 통행 금지
일부 교차로에서는 보행자 안전을 위해 좌회전이나 우회전 금지
- 0 : 자동차 자유 통행
- 1 : 자동차 통행 금지
- 2 : 좌회전, 우회전 금지 (왼쪽에서 오던 차는 오른쪽으로만, 위에서 오던 차는 아래쪽으로만 진행 가능)
==> 기존의 경로 탐색 알고리즘 보완

왼쪽 위 출발점에서 오른쪽 아래 도착점까지 자동차로 이동 가능한 전체 가능 경로수를 출력하는 프로그램
*/
int solution(int m, int n, vector<vector<int>> city_map) {
    
    // int dp[501][501] = {{1,},};
    // first : 윗쪽에서 오는 값
    // second : 왼쪽에서 오는 값
    vector<vector<pair<int, int>>> dp(501, vector<pair<int, int>>(501, {0, 0}));

    // vector<vector<pair<int,int> > > dp(501, {{0,0},});
    dp[0][0] = {1,1}; // 특수 케이스 초기화
    
    for(int r = 1; r < m; ++r){
        // 자동차 진입 금지만 아니면 이전 값을 그대로 가져올 수 있음 
        if((1 != city_map[r][0])){
            dp[r][0].first = dp[r - 1][0].first;
        }
        
    }

    for(int c = 1; c < n; ++c){
        // 자동차 진입 금지만 아니면 이전 값을 그대로 가져올 수 있음 
        if((1 != city_map[0][c])){
            dp[0][c].second = dp[0][c - 1].second;
        }
        
    }
    
    for(int r = 1 ; r < m ; ++r){
        for(int c = 1 ; c < n ; ++c){
            
            // if( (0 == r) && (0 == c)){
            //     continue;
            // }
            if( 1 != city_map[r][c]){
                // 이전 셀이 좌회전/우회전 금지였을 경우
                int fromTop = (2 == city_map[r - 1][c]) ?\
                              dp[r - 1][c].first : ((dp[r - 1][c].first + dp[r - 1][c].second) % MOD);
                int fromLeft = (2 == city_map[r][c - 1]) ?\
                              dp[r][c - 1].second : ((dp[r][c - 1].first + dp[r][c - 1].second) % MOD);
                
                dp[r][c] = {fromTop, fromLeft};
            }
            // 통행 불가 
            else if( 1 == city_map[r][c]){
                dp[r][c] = {0, 0};
            }
            // 우회전 또는 좌회전 금지
            else{
                // int fromTop = dp[r - 1][c].first;
                // int fromLeft = dp[r][c - 1].second;
                // dp[r][c] = {fromTop, fromLeft};
            }
        }
    }
    int answer = (dp[m - 1][n - 1].first + dp[m - 1][n - 1].second) % MOD ;
    return answer;
}