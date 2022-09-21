#include <cstdio>
#include <vector>
using namespace std; 

int N = 0, L = 0;
int map[101][101]={0,};
int ans = 0;

void slope(int stick, char dir){
    int cnt = 1;
    int diff = 0 ;
    for(int x = 0  ; x < N-1; x++){
        diff = ((dir == 'r')?(map[x+1][stick]-map[x][stick]):(map[stick][x+1]-map[stick][x]));
        if(diff == 0){
            cnt++;
        }
        // 길이가 L이상인 올라가는 경사로이면 cnt를 1로 초기화 (경사로의 끝)
        else if((diff == 1) && (cnt >= L)){
            cnt = 1;
        }
        // 경사로가 겹치지 않으면서 내려가는 경사로이면 cnt를 -L+1로 초기화 (경사로의 시작) 
        else if((diff == -1) && (cnt >= 0)){
            cnt = -L +1;
        }
        else{
            return;
        }
    }
    // 처음부터 끝까지 다 봤는데 cnt가 0 이상이면 answer가 1 증가한다 ! 
    if(cnt >= 0){
        ans++;
    }
}

int main(){
    scanf("%d %d",&N,&L);

    for(int y = 0 ; y < N  ;y++){
        for(int x = 0 ; x <  N  ; x++){
            scanf("%d",&map[y][x]);
        }
    }

    // row 방향과 column 방향을 모두 봐야함 
    for(int y = 0 ; y < N ; y++){
        slope(y,'r');
        slope(y,'c');
    }

    printf("%d\n",ans);


    return 0;
    
}