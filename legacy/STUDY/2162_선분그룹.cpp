#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int groups[3001] = {0,};
int parent[3001];

typedef struct Coord{
    long long x;
    long long y; 
    
    Coord operator- (const Coord & c) const{
        return {x-c.x,y-c.y};
    }
    bool operator< (const Coord & c) const{
        if(x == c.x){
            return y< c.y;
        }
        return x < c.x;
    }
}Coord;


int getCCW(const Coord & v1, const Coord & v2){
    long long ccw =v1.x*v2.y - v1.y*v2.x;
    if(ccw > 0){
        return 1;
    } 
    else if(ccw < 0){
        return -1;
    }
    return 0;
}

int getCCW(const Coord & c1, const Coord & c2, const Coord & c3){
    Coord v1 = c2-c1;
    Coord v2 = c3-c1;

    return  getCCW(v1,v2);
}

bool isCross(Coord & c1, Coord &c2, Coord & c3, Coord & c4){
    int AB = getCCW(c1,c2,c3)*getCCW(c1,c2,c4);
    int CD = getCCW(c3,c4,c1)*getCCW(c3,c4,c2);
    if(c2 < c1) swap(c1,c2);
    if(c4 < c3) swap(c3,c4);
    if((AB == 0) && (CD ==0)){
        if((c1 < c3 && c2 < c3) || (c4 < c2 && c4 < c1)){
            return false;
        }
    }
    return (AB<=0) && (CD<=0);
}

int find(int a){
    if(parent[a] == a){
        return a;
    }
    else{
        return parent[a]= find(parent[a]);
    }
}

void _union(int a, int b){
    int aRoot = find(a);
    int bRoot = find(b);
    parent[aRoot] = parent[bRoot];
    return;
}


int main(){
    int groupNum = 0;
    scanf("%d",&groupNum);

    Coord coords[3001][2];

    for(int num = 1; num <= groupNum;num++){
        scanf("%lld %lld %lld %lld",&coords[num][0].x,&coords[num][0].y,&coords[num][1].x,&coords[num][1].y);
        parent[num] = num;
    }

    for(int i = 1; i <= groupNum;i++){
        for(int j = i+1; j <= groupNum ; j++){
            if(isCross(coords[i][0],coords[i][1],coords[j][0],coords[j][1])){
                _union(i,j);
            }
         }
    }

    int maxUnion = 0;
    int groupCount = 0;
    for(int i = 1; i <= groupNum; i++){
        groups[find(i)]++;
        if(groups[find(i)]==1){
            groupCount++;
        }
        if(maxUnion < groups[find(i)]){
            maxUnion = groups[find(i)];
        }
    }

    printf("%d\n",groupCount);
    printf("%d\n",maxUnion);
    return 0;
}