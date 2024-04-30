#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int X = 0;
const int Y = 1;
const int NODEINFOIDX = 2;
const int LEFT = 3;
const int RIGHT = 4;
const int ROOT = 1;


bool compareNode(const vector<int> & first, 
                 const vector <int> & second){
    if(first[Y] == second[Y]){
        return first[X] < second[X];
    }
    return first[Y] > second[Y];
}

void makeEdgeInfo(vector<vector<int>> & nodeinfo){
    
    size_t totalNum = nodeinfo.size();

    for(int idx = 1; idx < static_cast<int> (totalNum); ++idx){
        int curNodeIdx = 0;
        int parentNodeIdx = -1;
        int dirOfAddNode = -1;
    
        while(curNodeIdx != -1){
            // left
            parentNodeIdx = curNodeIdx;
            
            if(nodeinfo[curNodeIdx][X] >= nodeinfo[idx][X]){
                curNodeIdx = nodeinfo[curNodeIdx][LEFT];
                dirOfAddNode = LEFT;
            }
            else{
                curNodeIdx = nodeinfo[curNodeIdx][RIGHT];
                dirOfAddNode = RIGHT;
            }
        }
        
        nodeinfo[parentNodeIdx][dirOfAddNode] = idx;
    }
}

void preorder(const int & idx, const vector<vector<int> >& nodeinfo, vector <int> & result){
    if(nodeinfo.size() < idx){
        return;
    }
    result.push_back(nodeinfo[idx][NODEINFOIDX]);
    preorder(nodeinfo[idx][LEFT],nodeinfo, result);
    preorder(nodeinfo[idx][RIGHT] ,nodeinfo,result);
}

void postorder(const int & idx, const vector<vector<int> >& nodeinfo, vector <int> & result){
    if(nodeinfo.size() < idx){
        return;
    }
    postorder(nodeinfo[idx][LEFT],nodeinfo, result);
    postorder(nodeinfo[idx][RIGHT] ,nodeinfo,result);
    result.push_back(nodeinfo[idx][NODEINFOIDX]);
    
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    // 정렬: nodeinfo의 item의 두 번째 값이 크고 첫 번째 값이 작은 것
    int totalNum = static_cast<int> (nodeinfo.size());
    
    for(int idx = 0; idx < totalNum; ++idx){
        nodeinfo[idx].push_back(idx + 1);
        nodeinfo[idx].push_back(-1);
        nodeinfo[idx].push_back(-1);
    }
    
    sort(nodeinfo.begin(), nodeinfo.end(),compareNode);

    makeEdgeInfo(nodeinfo);
    vector<vector<int>> answer(2);
    preorder(0, nodeinfo,answer[0]);
    postorder(0, nodeinfo,answer[1]);
    return answer;
}