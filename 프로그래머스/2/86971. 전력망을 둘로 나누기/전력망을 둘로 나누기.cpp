#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <queue>

using namespace std;
unordered_map<int, vector<int> > adjGraph; 

int bfs(bool visited[], int removeA, int removeB){
    
    queue <int> q;
    q.push(1);
    visited[1] = true;
    int cnt = 0;
    
    while(false == q.empty()){
        int t = q.front(); q.pop();
        ++cnt;
        int edgeSize = static_cast <int> (adjGraph[t].size());
        for(int edgeidx = 0; edgeidx < edgeSize; ++edgeidx){
            int curitem = adjGraph[t][edgeidx];
            
            if((t == removeA) && (curitem == removeB)){
                visited[removeB] = true;
            }
            else if((curitem == removeA) && (t == removeB)){
                visited[removeA] = true;
            }
            
            if(true == visited[curitem]){
                continue;
            }
            
            visited[curitem] = true;
            q.push(curitem);
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int wireSize = n - 1;
    int answer = 300;
    for(int idx = 0 ; idx < wireSize; ++idx){
        int s = wires[idx][0];
        int e = wires[idx][1];
        
        adjGraph[s].push_back(e);
        adjGraph[e].push_back(s);
    }
    
    for(int idx = 0 ; idx < n - 1; ++idx){
        int targetS = wires[idx][0];
        int targetE = wires[idx][1];
        bool visited[101] = {false};

        int sideLineNum = bfs(visited,targetS,targetE);
        int absLineNo = abs(2 * sideLineNum - n);
        answer = min(answer , absLineNo);
    }
    
    return answer;
}