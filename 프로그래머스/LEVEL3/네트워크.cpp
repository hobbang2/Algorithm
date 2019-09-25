#include <string>
#include <vector>
#include <queue>

using namespace std;

vector <bool> visitCheck(201,false);

int solution(int n, vector<vector<int> > computers) {
    int answer = 0;
    int numOfCum = (int)computers.size();
    queue <int> nodeQ;
    for(int idx = 0 ; idx < numOfCum; idx++){
        if(visitCheck[idx] == true){
            continue;
        }
        answer = answer + 1;
        visitCheck[idx] = true;
        nodeQ.push(idx);
        
        while(nodeQ.empty()==false){
            int curNode = nodeQ.front(); nodeQ.pop();
            for(int qIdx = 0; qIdx < numOfCum; qIdx++){
                if((computers[curNode][qIdx] == 1) &&(visitCheck[qIdx] == false)){
                    visitCheck[qIdx] =true;
                    nodeQ.push(qIdx);
                }
            }
        }
    }
    
    return answer;
}