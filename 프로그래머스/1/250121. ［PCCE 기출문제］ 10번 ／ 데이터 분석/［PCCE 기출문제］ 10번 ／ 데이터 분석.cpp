#include <string>
#include <vector>
#include <map>
#include <queue>
#include <utility>

using namespace std;

priority_queue < pair< int, int>, vector<pair <int, int> >, greater<pair<int, int> > > pq;



vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    map<string, int> idxMap;
    idxMap["code"] = 0; idxMap["date"] = 1; idxMap["maximum"] = 2; idxMap["remain"] = 3; 
    
    int dataSize = static_cast <int> (data.size());
    int checkIdx = idxMap[ext];
    int sortIdx = idxMap[sort_by];
    
    for(int idx = 0 ; idx < dataSize ; ++idx){
        if(data[idx][checkIdx] < val_ext){
            pair<int, int> d = make_pair(data[idx][sortIdx], idx);
            pq.push(d);
        }
    }
    
    while(!pq.empty()){
        int curIdx = pq.top().second; pq.pop();
        answer.push_back(data[curIdx]);
    }
    
    return answer;
}