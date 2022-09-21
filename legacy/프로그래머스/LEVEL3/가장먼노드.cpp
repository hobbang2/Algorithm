#include <string>
#include <vector>
#include <queue>

using namespace std;

vector <int> adjGraph[20001];
vector <bool> visitedCheck(20001,false);
int dist = -1;
int answer = 0;

int bfs(int curIdx){
    int curSize =0;
    queue <int> curNodeQ;
    visitedCheck[curIdx] = true;
    curNodeQ.push(curIdx);
    while(curNodeQ.empty() == false){
        curSize = (int)curNodeQ.size();
        for(int idx = 0 ; idx < curSize; idx++){
            int curNode = curNodeQ.front();curNodeQ.pop();
            for(int _idx = 0; _idx < (int)adjGraph[curNode].size();_idx++){
                int nextNode = adjGraph[curNode][_idx];
                if(visitedCheck[nextNode]==false){
                    visitedCheck[nextNode] = true;
                    curNodeQ.push(nextNode);
                }
            }
        }
    }
    return curSize;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int numOfEdge = (int)edge.size();
    for(int idx = 0 ; idx < numOfEdge; idx++){
        adjGraph[edge[idx][0]].push_back(edge[idx][1]);
        adjGraph[edge[idx][1]].push_back(edge[idx][0]);
    }
    answer =bfs(1);
    return answer;
}