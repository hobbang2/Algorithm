#include <cstdio>
#include <vector>

using namespace std;

typedef struct Coord{
    int x;
    int y; 
    
    
    Coord operator- (const Coord & c) const{
        return {x-c.x,y-c.y};
    }
}Coord;

int getCCW(const Coord & v1, const Coord & v2){
    return v1.x*v2.y - v1.y*v2.x;
}
int main(){
    Coord c[3];
    for(int num = 0 ; num < 3; num++){
        scanf("%d %d",&c[num].x,&c[num].y);
    }
    int ccw = getCCW(c[0]-c[1],c[0]-c[2]);
    if(ccw == 0){
        printf("0\n");
    }
    if(ccw > 0){
        printf("1\n");
    }
    if(ccw < 0){
        printf("-1\n");
    }
    return 0;
}