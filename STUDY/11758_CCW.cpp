#include <cstdio>
#include <vector>
using namespace std;

int main(){
    int coord[3][2] = {0,};
    for(int idx = 0 ;idx < 3; idx++){
        for(int c = 0 ; c < 2; c++){
            scanf("%d",&coord[idx][c]);
        }
    }

    int answer = ((coord[0][0]*coord[1][1] + coord[1][0]*coord[2][1]+coord[2][0]*coord[0][1])-
    (coord[1][0]*coord[0][1]+coord[2][0]*coord[1][1]+coord[0][0]*coord[2][1]));

    if(answer < 0){
        printf("%d\n",-1);
    }
    else if (answer > 0){
        printf("%d\n",1);
    }
    else{
        printf("%d\n",0);
    }
        
    return 0;

}