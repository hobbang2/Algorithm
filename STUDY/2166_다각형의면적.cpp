#include <cstdio>
#include <cmath>

using namespace std;

double CCW(double coord[][2]){
    double answer = ((coord[0][0]*coord[1][1] + coord[1][0]*coord[2][1]+coord[2][0]*coord[0][1])-
    (coord[1][0]*coord[0][1]+coord[2][0]*coord[1][1]+coord[0][0]*coord[2][1]));
    return answer;
}

int main(){
    int N = 0;
    double S = 0;
    double Coord[10001][2] = {0,};
    double target[3][2] = {0,};
    scanf("%d",&N);

    for(int n = 0 ; n < N ; n++){
        scanf("%lf %lf",&Coord[n][0],&Coord[n][1]);
    }

    for(int idx = 0; idx < N; idx++){
        target[1][0] = Coord[idx][0];
        target[1][1] = Coord[idx][1];
        if(idx + 1 == N){
            target[2][0] = Coord[0][0];
            target[2][1] = Coord[0][1];
        }
        else{
            target[2][0] = Coord[idx+1][0];
            target[2][1] = Coord[idx+1][1];
        }
        S += CCW(target);
    }

    S = round(abs(S)*5)/10;
    printf("%.1lf",S);

    return 0;

}