// boj.kr/1717 집합의 표현

#include <cstdio>
#include <vector>

using namespace std;

// UNION 0 a b
// FIND 1 a b
int rootArr[1000001];

int getParent(int target){
    if(rootArr[target] == target){
        return target;
    }
    else{
        return rootArr[target] = getParent(rootArr[target]);
    }
}

void UNION(int target1, int target2){
    int targetParent[2] = {getParent(target1),getParent(target2)};
    if(targetParent[0] < targetParent[1]){
        rootArr[target2] = targetParent[0];
    }
    else{
        rootArr[target1] = targetParent[1];
    }
}

bool FIND(int target1, int target2){
    if(rootArr[target1] == rootArr[target2]){
        return true;
    }
    return false;
}

int N,M;
void initRootArr(int size){
    for(int idx = 0; idx < size; idx++){
        rootArr[idx] = idx;
    }

}
int main(){
    // 10개의 노드가 있다고 생각합시다!
    scanf("%d %d",&N,&M);
    initRootArr(N);
    for(int m = 0 ; m < M ; m++){
        int order = 0, target1 = 0, target2 = 0;
        scanf("%d %d %d",&order,&target1, &target2);
        if(order == 0){
            UNION(target1, target2);
        }
        else{
            bool answer = FIND(target1,target2);
            answer ? printf("YES\n") : printf("NO\n");
        }
    }
    return 0;
}