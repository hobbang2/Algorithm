#include <string>
#include <vector>
#include <queue>
#include <utility>

const char HORSE  = 'R';
const char HUSTLE = 'D';
const char GOAL   = 'G';
const char ROAD   = '.';

enum{
    TOP = 0,
    DOWN,
    LEFT,
    RIGHT
};

using namespace std;

const int LIMIT = 101 * 101;
int BOARD_MAX_R = 100; // 주어진 board size로 갱신
int BOARD_MAX_C = 100; // 주어진 board size로 갱신

typedef struct QueueNode{
    int r;
    int c;
    int depth;
    
    QueueNode(int _r = 0, int _c = 0, int _d = 0):r(_r),c(_c), depth(_d)
    {
    }
}QueueNode;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool visited[101][101] = {false,};

bool isInMap(int r, int c){
    if( (r < 0) || (r >= BOARD_MAX_R)){
        return false;
    }
    
    if( (c < 0) || (c >= BOARD_MAX_C)){
        return false;
    }
    
    return true;
}

QueueNode getNextNode(
                   const QueueNode & curNode,
                   const int & dir, 
                   const vector<string> & board){
    
    int nextR = curNode.r;
    int nextC = curNode.c;

    do{
        nextR = nextR + dr[dir];
        nextC = nextC + dc[dir];
    }while((true == isInMap(nextR,nextC))&&(HUSTLE != board[nextR][nextC]));
    
    QueueNode retNode(nextR - dr[dir], nextC - dc[dir], curNode.depth + 1);
    
    return retNode;
}

int bfs(int startR, int startC, const vector<string> & board){
    int minMoveCnt = LIMIT;
    queue <QueueNode> q;
    q.push(QueueNode(startR, startC, 0));
    visited[startR][startC] = true;
    
    while(false == q.empty()){
        QueueNode curNode = q.front(); q.pop();
        const int & nodeDept = curNode.depth;
        
        
        if(GOAL == board[curNode.r][curNode.c]){
            minMoveCnt =  (minMoveCnt > nodeDept)? nodeDept : minMoveCnt;
            continue;
        }
        
        for(int diridx = 0 ; diridx < 4; ++diridx){
            QueueNode nextNode = getNextNode(curNode, diridx, board);
            
            if(true == visited[nextNode.r][nextNode.c]){
                continue;
            }
            visited[nextNode.r][nextNode.c] = true;
            q.push(nextNode);
        }
        
    }
    return LIMIT == minMoveCnt? -1 : minMoveCnt;
}

int solution(vector<string> board) {

    int answer = 0;
    int horseR = -1; 
    int horseC = -1;
    BOARD_MAX_R = static_cast<int> (board.size());
    BOARD_MAX_C = static_cast<int> (board[0].size());
    bool bFindFlag = false;
    for(int r = 0 ; r < BOARD_MAX_R; ++r){
        for(int c = 0 ; c < BOARD_MAX_C; ++c){
            if(HORSE == board[r][c]){
                bFindFlag = true;
                horseR = r;
                horseC = c;
                break;
            }
        }
        if(true == bFindFlag){
            break;
        }
    }

    answer = bfs(horseR, horseC, board);
    
    return answer;
}