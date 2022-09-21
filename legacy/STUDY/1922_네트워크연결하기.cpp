/* MST : Minimum Spanning Tree
- 모든 노드들이 서로 연결되도록 하면서 가중치의 합이 최소가 되는 edge들의 부분 집합을 찾음 
- `Kruskal`과 `Prim` 알고리즘을 이용하여 안전한 edge를 찾아나간다.
*/

/* Kruskal Algorithm
- edge 들을 가중치의 오름차순으로 정렬 
- 이미 선택된 edge들과 cycle을 형성하지 않는 edge들을 순서대로 선택
- n-1개의 edge가 선택되면 종료 
*/

#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int parent[1001];

typedef struct Node{
    int start;
    int end;
    int weight;

    bool operator< (const Node & node)const{
        return weight > node.weight;
    }
}Node;


int find(int idx){
    if(parent[idx] == idx){
        return idx;
    }
    else{
        return parent[idx] = find(parent[idx]);
    }
}

void _union(int a, int b){
    int aRoot = find(a);
    int bRoot = find(b);
    parent[aRoot] = parent[bRoot];
    return;
}


int main(){
    int N = 0, M = 0 ;
    int sum = 0;
    Node node = {0,0,0};
    priority_queue<Node> pq;
    scanf("%d",&N);
    scanf("%d",&M);

    for(int n = 1; n<=N;n++){
        parent[n] = n;
    }

    for(int m = 1; m <= M; m++){
        scanf("%d %d %d",&node.start,&node.end,&node.weight);
        pq.push(node);
    }

    Node initNode = {0,0,0};
    int cnt = 0;
    while(pq.empty()==false){
        if (cnt == N-1){
            break;
        }
        initNode =pq.top(); pq.pop();
        if(find(initNode.start) != find(initNode.end)){
            cnt++;
            sum += initNode.weight;
            _union(initNode.start,initNode.end);
        }
    }

    printf("%d\n",sum);


    return 0;
}