#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int N = 0;
int map[101][101];
int dir_x[4] = {1,0,-1,0};
int dir_y[4] = {0,-1,0,1};

typedef struct Curve{
    int y,x;
    int d;
    int gene;
}Curve;

vector <Curve> dragonCurve;

void initVector(vector <Curve> & targetVec){
    vector <Curve> emptyVec;
    targetVec.swap(emptyVec);
    return;
}

void gameStart(const Curve & initCurve){
    dragonCurve.push_back(initCurve);

    for(int cnt = 1; cnt <= initCurve.gene; cnt++){
        int pointNum = (int)dragonCurve.size();
        Curve lastCurve = dragonCurve.back();

        for(int num = 0; num < pointNum; num++){
            Curve curCurve = dragonCurve[num];
            map[curCurve.y][curCurve.x] = 1;
            Curve nextCurve = {-102,-102,curCurve.d,curCurve.gene};
            if(cnt == 1){
                nextCurve.y = curCurve.y + dir_x[curCurve.d];
                nextCurve.x = curCurve.x + dir_y[curCurve.d];
            }
            else{
                nextCurve.y=  -curCurve.x + lastCurve.y;
                nextCurve.x = curCurve.y+ lastCurve.x;
            }
            if(map[nextCurve.y][nextCurve.x] == 0){
                dragonCurve.push_back(nextCurve);
            }
            
        }
    }
}


int main(){
    scanf("%d",&N);
    
    for(int n = 1 ; n  <= N; n++){
        Curve curCurve = {-102,-102,-1,-1};
        scanf("%d %d %d %d",&curCurve.x,&curCurve.y, &curCurve.d, &curCurve.gene);
        gameStart(curCurve);
        initVector(dragonCurve);
    }

    int ans = 0;
    for(int y = 0; y < 99; y++){
        for(int x = 0 ; x < 99; x ++){
            if(map[y][x] & map[y][x+1] & map[y+1][x] & map[y+1][x+1]){
                ans++;
            }
        }
    }

    printf("%d ",ans);

    return 0;
}