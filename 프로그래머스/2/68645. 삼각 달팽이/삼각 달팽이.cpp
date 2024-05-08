#include <string>
#include <vector>

using namespace std;

// 하, 우, 왼쪽 대각선 위

int dr[3] = {1, 0, -1};
int dc[3] = {0, 1, -1};

int board[1001][1001] = {0,};

bool is_in_map(int r, int c, int n){
    if( (r < 0) || (c < 0)){
        return false;
    }
    if( (r >= n) || (c >= n)){
        return false;
    }
    return true;
}

void fill_board(int n){

    int diridx = 0 ;
    int totalcnt = ((n * (n + 1)) / 2 );
    int curr = 0 ; int curc = 0 ; 
    board[0][0] = 1;
    int limitcnt = 0;
    
    for(int numcnt = 2; numcnt <= totalcnt;){
        
        int nextr = curr + dr[diridx];
        int nextc = curc + dc[diridx];
        
        if((false == is_in_map(nextr, nextc, n))
           ||( 0 < board[nextr][nextc])){
            diridx = (diridx + 1) % 3; 
            limitcnt += 1;
            continue;
        }
        limitcnt += 1;
        
        board[nextr][nextc] = numcnt++;
        curr = nextr;
        curc = nextc;
    }
    return;
}

vector<int> solution(int n) {
    vector<int> answer;
    fill_board(n);
    
    for(int r = 0 ; r < n; ++r){
        for(int c = 0; c <=r ; ++c){
            answer.push_back(board[r][c]);
        }
    }
    
    return answer;
}