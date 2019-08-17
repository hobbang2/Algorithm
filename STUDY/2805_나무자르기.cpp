#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0, M = 0 ; 
vector <int> trees;

long long getMaximum(int start, int end){
    if(start >= end){
        // sum >= M 일 때 호출된 start, end가 정답 !_! 
        return start;
    }

    int mid = (start+end+1)/2;

    long long sum = 0;
    for(int idx = 0 ; idx < (int)trees.size();idx++){
        if(trees[idx] > mid){
            sum += (trees[idx]-mid);
        }
    }

    if(sum >= M){
        
        getMaximum(mid,end);
    }
    else{
        getMaximum(start,mid-1);
    }
}

int main(){
    int _min = 2000000001;
    int _max = -1;


    scanf("%d %d",&N,&M);
    while(N--){
        int treeH = 0;
        scanf("%d",&treeH);
        
        if(_min > treeH){
            _min = treeH;
        }

        if(_max < treeH){
            _max = treeH;
        }
        trees.push_back(treeH);
    }

    long long answer = getMaximum(0,_max);
    printf("%lld\n",answer);

    return 0;
}