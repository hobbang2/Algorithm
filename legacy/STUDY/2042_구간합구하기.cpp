#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

int N,M,K;
ll nums[1000001];

ll makeTree(int start,int end,int node,vector <ll> & tree){
    if(start == end){
        return tree[node]= nums[start];
    }
    int mid = (start+end)/2;
    return tree[node] = makeTree(start,mid,node*2,tree) + makeTree(mid+1,end,node*2+1,tree);
}

ll getSum(int start,int end,int node,ll left, ll right,vector <ll> & tree){
    if(left > end || right < start){
        return 0;
    }
    if(left <= start && end <= right){
        return tree[node];
    }
    int mid =(start+end)/2;
    return getSum(start,mid,node*2,left,right,tree)+getSum(mid+1,end,node*2+1,left,right,tree);
}

void updateValue(int start,int end,int node,ll idx,ll modifyValue,vector <ll> & tree){
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
    vector <ll> Tree(locatedSpace,0);
    
    for(int idx = 0; idx < N;idx++){
        scanf("%lld",&nums[idx]);
    }

    makeTree(0,N-1,1,Tree);

    int cnt = M+K;

    while(cnt--){
        int order = 0;
        ll idx[2] = {0,};
        scanf("%d %lld %lld",&order,&idx[0],&idx[1]);
        idx[0]--;
        switch(order){
            case 2:
                idx[1]--;
                printf("%lld\n",getSum(0,N-1,1,idx[0],idx[1],Tree));
                break;
            case 1:
                ll diff = idx[1]-nums[idx[0]];
                nums[idx[0]] = idx[1];
                updateValue(0,N-1,1,idx[0],diff,Tree);
        }
    }


    return 0;
}