#include <cstdio>
#include <vector>

using namespace std;

int N,M,K;
long long nums[1000001];

long long makeTree(int start,int end,int node,vector <long long> & tree){
    if(start == end){
        return tree[node]= nums[start];
    }
    int mid = (start+end)/2;
    return tree[node] = makeTree(start,mid,node*2,tree) + makeTree(mid+1,end,node*2+1,tree);
}

long long getSum(int start,int end,int node,int left, int right,vector <long long> & tree){
    if(left > end || right < start){
        return 0;
    }
    if(left <= start && end <= right){
        return tree[node];
    }
    int mid =(start+end)/2;
    return getSum(start,mid,node*2,left,right,tree)+getSum(mid+1,end,node*2+1,left,right,tree);
}

void updateValue(int start,int end,int node,int idx,int modifyValue,vector <long long> & tree){
    if(idx < start || idx > end){
        return;
    }
    tree[node]+=modifyValue;
    if(start == end){
        return;
    }
    int mid  = (start+end)/2;
    updateValue(start,mid,node*2,idx,modifyValue,tree);
    updateValue(mid+1,end,node*2+1,idx,modifyValue,tree);

}


int main(){
    scanf("%d %d %d",&N,&M,&K);
    int locatedSpace = 4*N;
    vector <long long> Tree(locatedSpace,0);
    
    for(int idx = 0; idx < N;idx++){
        scanf("%d",&nums[idx]);
    }

    makeTree(0,N-1,1,Tree);

    int cnt = M+K;
    while(cnt--){
        int order = 0 , idx[2] = {0,};
        scanf("%d %d %d",&order,&idx[0],&idx[1]);
        switch(order){
            case 1:
                printf("%d\n",getSum(0,N-1,1,idx[0],idx[1],Tree));
                break;
            case 2:
                int diff = nums[idx[0]-1] - idx[1];
                updateValue(0,N-1,1,idx[0],diff,Tree);
        }
    }


    return 0;
}