#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;

/*
레버가 있는 칸으로 이동 - 레버 당긴 후 미로를 빠져나가는 문이 있는 칸으로 이동
미로 탈출에 필요한 최소시간 return
*/
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int MAXR = 101; int MAXC = 101;

bool isInMap(int r, int c){
    
    if((r < 0) || (c < 0)){
        return false; 
    }
    if((r >= MAXR) || (c >= MAXC)){
        return false;
    }
    return true;
}

int bfs(const vector<string> & maps, int coord, int goal){
    
    int ret = -1;
    bool visited[101][101] = {{false,},};
    queue <pair<int, int> > q;
    q.push({coord, 0});
    visited[coord / 1000][coord % 1000] = true;
    
    while(false == q.empty()){
        pair<int, int> curNode = q.front(); q.pop();
        
        if(curNode.first == goal){
            ret = curNode.second;
            break;
        }
        
        int curR = curNode.first / 1000;
        int curC = curNode.first % 1000;
        
        for(int diridx = 0 ; diridx < 4; ++diridx){
            int nextR = curR + dr[diridx];
            int nextC = curC + dc[diridx];
            
            if( false == isInMap(nextR, nextC)){
                continue;
            }
            else if( 'X' == maps[nextR][nextC]){
                continue;
            }
            else if(true == visited[nextR][nextC]){
                continue;
            }
            else{
                visited[nextR][nextC] = true;
                int nextCoord = nextR * 1000 + nextC;
                int nextDepth = curNode.second + 1;
                
                q.push({nextCoord, nextDepth});
            }
        }
    }
    
    return ret;
}

int findCoord(const vector<string> & maps, char targetstr){
    
    for(int r = 0; r < MAXR; ++r){
        for(int c = 0 ; c < MAXC; ++c){
            if(targetstr == maps[r][c]){
                return (r * 1000) + c;
            }
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    MAXR = maps.size();
    MAXC = maps[0].size();

    int startCoord = findCoord(maps, 'S');
    int levarCoord = findCoord(maps, 'L');
    int endCoord = findCoord(maps, 'E');
    int path[2] = {0, 0};
    path[0] = bfs(maps, startCoord,  levarCoord);
    path[1] = bfs(maps, levarCoord, endCoord);
    int answer = -1;
    
    if(false == ((-1 == path[0]) || (-1 == path[1]))){
        answer = path[0] + path[1];
    }
    
    return answer;
}