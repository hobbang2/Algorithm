#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <map>

using namespace std;
const int MAX_COST = ( 200 * 100000 ) + 10 ;


vector<int> getDijkstraArr(int n,int s, map<int, vector<pair <int, int> > > & adjGraph){
    
    vector <int> dijkstraArr(n + 1,MAX_COST);
    dijkstraArr[s] = 0;
    priority_queue<pair<int,int>,
                   vector<pair<int, int> >,
                   greater<pair<int,int> > > pq;
    pq.push({0, s});
    
    while(false == pq.empty()){
        pair<int, int> curNode = pq.top();pq.pop();
        int curWeight = curNode.first;
        int curNodeIdx = curNode.second;
        
        for( auto it: adjGraph[curNodeIdx]){
            int nextNode = it.first;
            int advocateWeight = it.second;
            if(dijkstraArr[nextNode] > curWeight + advocateWeight){
                dijkstraArr[nextNode] = curWeight + advocateWeight;
                pq.push({curWeight + advocateWeight, nextNode});
            }
        }
    }
    return dijkstraArr;
}



// 목표지점 두군데 
// 최단거리
// 다익스트라 ? 
    
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    map<int, vector<pair <int, int> > > adjGraph;

    int edgeSize = static_cast<int> (fares.size());
    
    // 인접 행렬
    for(int idx = 0 ; idx < edgeSize; ++idx){
        int c = fares[idx][0];
        int d = fares[idx][1];
        int f = fares[idx][2];
        
        adjGraph[c].push_back({d, f});
        adjGraph[d].push_back({c, f});
    }
    
    vector<int> startDijkstra = getDijkstraArr(n, s, adjGraph);
    vector<int> aDijkstra = getDijkstraArr(n, a, adjGraph);
    vector<int> bDijkstra = getDijkstraArr(n, b, adjGraph);
    
    int minValue = MAX_COST;
    int minIdx = -1;
    answer = startDijkstra[a] + startDijkstra[b];
    for(int idx = 1 ; idx <= n; ++idx){
        int tmpAnswer = startDijkstra[idx] + aDijkstra[idx] + bDijkstra[idx] ;
        
        if(answer > tmpAnswer){
            answer = tmpAnswer;
        }
    }
    
    
    return answer;
}