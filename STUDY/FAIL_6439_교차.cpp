#include <cstdio>
#include <vector>

using namespace std;

typedef struct Coord{
    int x;
    int y;

    Coord operator- (const Coord & c1)const{
        return {x-c1.x,y-c1.y};
    }

    bool operator< (const Coord & c1) const{
        if(x == c1.x){
            return y < c1.y;
        }
        else {
            return x < c1.x;
        }
    }
}Coord;

int getCCW(const Coord & v1, const Coord & v2){
    return (v1.x*v2.y-v1.y*v2.x);
}

int getCCW(const Coord & c1, const Coord & c2, const Coord & c3){
    return getCCW(c2-c1,c3-c1);
}


int isCross(Coord & c1, Coord & c2, Coord & c3, Coord & c4){
    int AB = getCCW(c1,c2,c3) * getCCW(c1,c2,c4);
    int CD = getCCW(c3,c4,c1)*getCCW(c3,c4,c2);
    if(c2 < c1) swap(c1,c2);
    if(c4 < c3) swap(c3,c4);
    if((AB == 0) &&(CD == 0)){
        if(((c1 < c3)&&(c2 < c3))||((c4 < c2) && (c4 < c1))){
            return false;
        }
    }
    return (AB<=0) && (CD<=0);
}

int main(){
    int tc = 0;
    scanf("%d",&tc);
    for(int t = 1 ; t <= tc; t++){
        Coord line[2]={0,};
        Coord square[2] = {0,};
        scanf("%d %d %d %d %d %d %d %d",&line[0].x,&line[0].y,&line[1].x,&line[1].y,&square[0].x,&square[0].y,&square[1].x,&square[1].y);
        char answer = 'T';
        if(isCross(line[0],line[1],square[0],square[1])==false){
            answer = 'F';
        }
        printf("%c\n",answer);
    }
    return 0;
}