#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0 , M = 0 , H = 0;
int answer = 987654321;
vector <vector <int> > map(31,vector<int> (11,0));

bool startGame(){
    int curY = 1; 
    int curX = 1;
    for(int x = 1; x <=N; x++){
        curX = x;
        for(int y = 1; y<= H;y++){
            if(map[y][curX] == 1){
                curX+=1;
            }
            else if(map[y][curX-1]==1){
                curX-=1;
            }
        }
        if(curX != x){
            return false;
        }
    }
    return true;
}

void takeBridge(int idx, int cnt, int targetCnt){
    if(answer != 987654321){
        return;
    }
    if(cnt == targetCnt){
        bool ans = startGame();
        if(ans == true){
            
            if((answer > targetCnt)){
                answer = targetCnt;
            }
        }
        return;
    }
    for(int y = idx ; y<=H;y++){
        for(int x = 1 ; x <=N-1;x++){
            if((map[y][x] == 0)&&(map[y][x+1]== 0)&&(map[y][x-1]==0)){
                map[y][x] = 1;
                takeBridge(y,cnt+1,targetCnt);
                map[y][x] = 0;
            }
        }
    }
    
    return;
}

int main(){
    scanf("%d %d %d",&N,&M,&H);
    if(M == 0){
        answer = 0;
    }
    else{
        int a = 0 , b = 0 ;
        for(int m = 1; m <=M;m++)
        {
            scanf("%d %d",&a,&b);
            map[a][b] = 1;
        }
            takeBridge(1,0,0);
            takeBridge(1,0,1);
            takeBridge(1,0,2);
            takeBridge(1,0,3);
    }
    printf(answer == 987654321 ? "-1\n" :"%d\n",answer);

    return 0;
}