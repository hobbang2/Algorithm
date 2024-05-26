#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map <string, int> name2idx;
    int playercnt = players.size();
    vector <string> idx2name (playercnt + 1, "");
    
    for(int idx = 0 ;idx < playercnt; ++idx){
        name2idx[players[idx]] = idx + 1;
        idx2name[idx + 1] = players[idx];
    }

    int callcnt = callings.size();
    
    for(int itemidx = 0 ; itemidx < callcnt; ++itemidx){
        const string & curCallName = callings[itemidx];
        int curidx              = name2idx[curCallName];
        const string priorName = idx2name[curidx - 1];
        
        name2idx[curCallName] = curidx - 1;
        name2idx[priorName]   = curidx;
        idx2name[curidx - 1]  = curCallName;
        idx2name[curidx]      = priorName;
        
    }
    
    vector<string> answer;
    
    for(int idx = 0 ;idx < playercnt; ++idx){
        answer.push_back(idx2name[idx + 1]);
    }

    
    return answer;
}