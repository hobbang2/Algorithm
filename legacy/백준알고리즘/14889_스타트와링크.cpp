#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
int mid = 0;
int ans = 987654321;
int map[21][21] = {0,}; 
bool person[21] = {false,};

void devideStartLink(int idx, int cnt){
    if((idx >= N)||(cnt > mid)){
        return;
    }
    if(cnt == mid){
        int startPower = 0;
        int linkPower = 0;
        vector <int> startTeam;
        vector <int> linkTeam;
        for(int n =0 ; n < N; n++){
            if(person[n] == true){
                startTeam.push_back(n);
            }
            else{
                linkTeam.push_back(n);
            }
        }

        for(int i = 0 ; i < mid ; i++){
            for(int j = i+1 ; j < mid ; j++){
                startPower += map[startTeam[i]][startTeam[j]]+map[startTeam[j]][startTeam[i]];
                linkPower += map[linkTeam[i]][linkTeam[j]]+ map[linkTeam[j]][linkTeam[i]];
            }
        }
        ans = min(ans,abs(startPower-linkPower));
        return;
    }
    for(int nextIdx = idx ; nextIdx < N-1;nextIdx++){
        person[nextIdx] = true;
        devideStartLink(nextIdx+1,cnt+1);
        person[nextIdx] =false;

    }
    return;
}


int main(){
    scanf("%d",&N);
    mid = N >> 1;
    for(int y = 0; y<N;y++){
        for(int x = 0 ; x < N ; x++){
            scanf("%d",&map[y][x]);
        }
    }   
    devideStartLink(0,0);
    printf("%d\n",ans);

    return 0;
}