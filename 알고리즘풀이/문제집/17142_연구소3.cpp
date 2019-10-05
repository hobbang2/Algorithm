#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

enum {PATH,WALL,VIRUS,ACTIVE=9};
typedef struct Virus{
    int y, x;
    Virus(int _y =0 ,int _x=0):y(_y),x(_x){
    }
}Virus;

// 북 남 서 동;
int dirY[4] = {-1,1,0,0};
int dirX[4] = {0,0,-1,1};
int answer = 987654321;
int N,M;
vector <vector <int> > map(51,vector<int> (51,0));
vector <Virus> virusVec;
vector <bool> check(11,false);

bool isInMap(int y, int x){
    if(y <= 0 || x <= 0 || y > N || x > N){
        return false;
    }
    return true;
}

bool isInMap(const Virus & v){
    if(v.y <= 0 || v.x <= 0 || v.y > N || v.x > N){
        return false;
    }
    return true;
}

int spreadVirus(queue <Virus> & virusQ,vector <vector <int> > & cpyMap){
    int curTime = 0;
    while(virusQ.empty()== false){
        curTime +=1;
        int curSize = (int)virusQ.size();
        for(int s = 1 ; s <= curSize; s++){
            Virus curVirus = virusQ.front();virusQ.pop();
            for(int d = 0; d <4; d++){
                int nextY = curVirus.y+dirY[d];
                int nextX = curVirus.x+dirX[d];
                if(isInMap(nextY,nextX)==true){
                    cpyMap[nextY][nextX] = ACTIVE;
                    Virus nextVirus(nextY,nextX);
                    virusQ.push(nextVirus);
                }
            }

        }
    }
    return curTime;
}

bool isSwWinner(vector <vector <int> > & cpyMap){
    for(int y = 1; y <= N ; y++){
        for(int x = 1; x <= N; x++){
            if(cpyMap[y][x] == PATH){
                return false;
            }
        }
    }
    return true;
}

void swTime(int idx,int cnt,int numOfVirus){
    if((idx > numOfVirus)||(cnt > numOfVirus)){
        return;
    }
    if(cnt == M){
        // 최소시간 구하기
        vector <vector <int> > cpyMap = map;
        queue <Virus> virusQ;
        for(int v = 1 ; v <= numOfVirus; v++){
            if(check[v]==true){
                Virus curVirus = virusVec[v];
                cpyMap[curVirus.y][curVirus.x] = ACTIVE;
                virusQ.push(virusVec[v]);
            }
        }
        int curTime = spreadVirus(virusQ,cpyMap);
        // 점령당함? 
        if(isSwWinner(cpyMap)==true){
            answer = (answer > curTime) ? curTime : answer;
        }
        return;
    }
    check[idx]= true;
    swTime(idx+1,cnt+1,numOfVirus);
    check[idx]= false;
}

int main(){
    scanf("%d %d",&N,&M);
    // map 입력받기 
    for(int y =  1; y <= N; y++){
        for(int x = 1; x <= N; x++){
            scanf("%d",&map[y][x]);
            if(map[y][x] == 2){
                Virus curVirus(y,x);
                virusVec.push_back(curVirus);
            }
        }
    }
    int numOfVirus = (int)virusVec.size();
    swTime(1,0,numOfVirus);
    answer = (answer == 987654321)?(-1):(answer);
    printf("%d\n",answer);
    return 0;
}