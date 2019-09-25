#include <string>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

vector <int> adjGraph[101];
vector <int> exOrder(101,-1);
vector <int> updateNode(101,0);

int solution(int n, vector<vector<int>> results) {
    vector <int> inorderEdge(n+1,0);
    vector <int> startNode;
    int answer = 0;
    int numOfEdge = (int)results.size();
    
    for(int idx = 0; idx < numOfEdge;idx++){
        adjGraph[results[idx][0]].push_back(results[idx][1]);
        inorderEdge[results[idx][1]] += 1;
    }
    
    // 진입간선이 0개인 것을 startNode로 넣어줍니다.
    for(int idx = 1 ; idx <= n;idx++){
        if(inorderEdge[idx] == 0){
            startNode.push_back(idx);
        }
    }

    // 시작 노드를 돌면서 순번을 갱신합니다. 
    for(int startIdx = 0; startIdx < (int)startNode.size();startIdx++){
        vector <int> cpyInorder = inorderEdge;
        queue <int> curQ;
        int cnt = 0;
        
        cpyInorder[startNode[startIdx]] = -1;
        curQ.push(startNode[startIdx]);
        
        while(curQ.empty()==false){
            int curSize = (int)curQ.size();
            for(int s = 0 ; s < curSize; s++){
                int curNode = curQ.front();curQ.pop();
                cnt += 1;
                // 줄 세우면서 지난 번이랑 비교, 바뀌었으면 update + 1
                if(exOrder[curNode]!=cnt){
                    exOrder[curNode] = cnt;
                    updateNode[curNode] += 1;
                }
             
                for(int _idx = 0;_idx < (int)adjGraph[curNode].size();_idx++){
                    int nextNode = adjGraph[curNode][_idx];
                    (cpyInorder[nextNode] -= 1);
                    if(cpyInorder[nextNode]==0){
                        cpyInorder[nextNode] = -1;
                        curQ.push(nextNode);
                        if(adjGraph[nextNode].size()==0){
                            answer-=1;
                        }
                    }
                }
                
                for(int nodeIdx = 1; nodeIdx <= n; nodeIdx++){
                    if(cpyInorder[nodeIdx]==0){
                        cpyInorder[nodeIdx] = -1;
                        curQ.push(nodeIdx);
                    }
                }
            }
        }
    }

    for(int idx = 1 ; idx <= n; idx++){
        if(updateNode[idx]==1){
            answer +=1;
        }
    }
    return answer;
}