// 2019 9월 삼성전자 A형 문제 
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 987654321

int N , M ; 
int dirX[4] = {1,-1,0,0};
int dirY[4] = {0,0,1,-1};

int map[11][11];
int parent[12];
vector <vector<int> > weightMap(12,vector <int> (12,INF));

typedef struct Edge{
    int y,x;
    int weight;
    Edge(int _y=0,int _x=0, int _weight=0){
        y = _y, x = _x , weight = _weight;
    }
    bool operator< (Edge & e){
        if(weight < e.weight){
            return true;
        }
        return false;
    }
}Edge;

vector <Edge> edgeSet;


int findParent(int nodeNum){
    if(parent[nodeNum] == nodeNum){
        return nodeNum;
    }
    else{
        return parent[nodeNum] = findParent(parent[nodeNum]);
    }
}

void UNION(int left, int right){
    int leftParent = findParent(left);
    int rightParent = findParent(right);
    if(leftParent < rightParent){
        parent[rightParent] = leftParent; 
    }
    else{
        parent[leftParent] = rightParent;
    }
}

bool FIND(int left, int right){
    int leftParent = findParent(left);
    int rightParent = findParent(right);
    if(leftParent == rightParent){
        return true;
    }
    else{
        return false;
    }
}

bool isInMap(int y,int x){
    if(y > N || x > M || y <= 0 || x <= 0){
        return false;
    }
    return true;
}

void devideIsland(int y,int x,int cnt){
    if(isInMap(y,x)==false){
        return;
    }
    if(map[y][x]!=1){
        return;
    }
    map[y][x] = cnt;
    for(int d = 0 ; d < 4; d++){
        int nextY = y + dirY[d];
        int nextX = x + dirX[d];
        devideIsland(nextY,nextX,cnt);
    }
}

void findBridge(int curIsland,int y,int x,int dY,int dX,int cnt){
    if(isInMap(y,x) == false){
        return;
    }
    if(map[y][x]==curIsland){
        return;
    }

    if(map[y][x]==0){
        findBridge(curIsland,y+dY,x+dX,dY,dX,cnt+1);
    }
    else{
        int nextIsland = map[y][x];
        if((cnt!= 1)&&(weightMap[curIsland][nextIsland] > cnt)){
            weightMap[curIsland][nextIsland] = cnt;
            weightMap[curIsland][nextIsland] = cnt;
        }
    }
    return;
}


int main(){
    // 맵을 입력 받습니다. 
    scanf("%d %d",&N,&M);
    for(int y = 1; y <= N; y++){
        for(int x= 1; x <= M; x++){
            scanf("%d",&map[y][x]);
        }
    }

    // 섬을 나눕니다. 
    int cnt = 2;
    for(int y = 1; y <= N; y++){
        for(int x= 1; x <= M; x++){
            if(map[y][x] == 1){
                devideIsland(y,x,cnt);
                cnt += 1;
            }
        }
    }
 
    // 다리를 찾습니다. 
    for(int y = 1; y <= N; y++){
        for(int x= 1; x <= M; x++){
            if(map[y][x] != 0){
                for(int d = 0 ; d < 4; d++){
                    findBridge(map[y][x],y+dirY[d],x+dirX[d],dirY[d],dirX[d],0);
                }
            }
        }
    }

    // edge들을 vector 에 넣어주기
    for(int idx = 2; idx < cnt; idx++){
        parent[idx] = idx;
        for(int nextIdx = idx+1 ;nextIdx < cnt ;nextIdx++){
            if(weightMap[idx][nextIdx] != INF){
                Edge curEdge(idx,nextIdx,weightMap[idx][nextIdx]);
                edgeSet.push_back(curEdge);
            }
        }
    }

    // kruskal algorithm 사용을 위한 edge 정렬 
    sort(edgeSet.begin(),edgeSet.end());

    int numOfEdge = (int)edgeSet.size();
    int answer = 0;
    
    int nodeCnt = 0;
    for(int idx = 0; idx < numOfEdge;idx++){
        if(FIND(edgeSet[idx].y,edgeSet[idx].x)==false){
            nodeCnt +=1;
            answer += edgeSet[idx].weight;
            UNION(edgeSet[idx].y,edgeSet[idx].x);
        }
    }
    
    // cnt가 2부터 시작했으므로 원점으로 돌려주기
    cnt -=2;

    // 선택된 edge의 수는 node의 수 -1
    if(nodeCnt != (cnt-1)){
        answer = -1;
    }
    printf("%d\n",answer);
    return 0;
}