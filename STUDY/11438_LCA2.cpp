#include <cstdio> 
#include <vector>

using namespace std;

typedef struct Coord{
    int start;
    int end;

}Coord;

vector <Coord> trees;

int main(){
    int N = 0;
    Coord node = {0,0};
    scanf("%d",&N);

    for(int n = 1; n <=N;n++){
        scanf("%d %d",&node.start,&node.end);
        trees.push_back(node);
    }

    return 0;
}