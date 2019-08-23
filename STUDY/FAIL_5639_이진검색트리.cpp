#include <cstdio>
#include <vector>

using namespace std;
int cnt = 0;
void makeTree(int idx,vector <int> & tree, vector <int> & preOrder){
    if(cnt >= preOrder.size() || preOrder[cnt] == 0){
        return;
    }
    tree[idx] = preOrder[cnt++];
    makeTree(2*idx,tree,preOrder);
    makeTree(2*idx+1,tree,preOrder);
}

void postOrder(int idx,vector <int> & tree){
    if(idx >= tree.size() || tree[idx] == 0){
        return;
    }
    postOrder(2*idx,tree);
    postOrder(2*idx+1,tree);
    printf("%d\n",tree[idx]);
}


int main(){
    vector <int> preOrderResult;
    int num = 0;
    int treeSize = 0;
    // while(cin >> num)
    // while(scanf("%d",&num)==1){
    //     preOrderResult.push_back(num);
    // }
    int N = 9;
    while(N--){
        scanf("%d",&num);
        preOrderResult.push_back(num);
    }

    treeSize = (int)preOrderResult.size()*100;
    vector <int> Tree(treeSize,0);

    makeTree(1,Tree,preOrderResult);
    printf("-------------\n");
    //postOrder(1,Tree);
    for(int idx  = 0 ; idx < Tree.size();idx++){
        printf("%d\n",Tree[idx]);
    }
    return 0;
}