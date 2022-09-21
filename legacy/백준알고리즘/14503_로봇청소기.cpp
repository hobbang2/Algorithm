
#include <cstdio>
#include <vector>

using namespace std;

enum {PATH,WALL,DONE=7};

int N,M;
int ans;
int map[51][51] = {0,};
int dir_x[4] = {0,1,0,-1};
int dir_y[4] = {-1,0,1,0};

typedef struct Coord{
    int y;
    int x;
    int dir;
    Coord(int _y, int _x, int _dir){
        y = _y; x= _x; dir = _dir;
    };
}Coord;

bool canRobotGo(int y,int x){
    if(y < 0 || y >= N || x < 0 || x >= M){
        return false;
    }
    if(map[y][x] == PATH){
        return true;
    }
    return false;
}

void StartCleaning(Coord & curRobot){
    for(;;){
        if(map[curRobot.y][curRobot.x] == PATH){
            map[curRobot.y][curRobot.x] = DONE;
            ans++;
        }
        bool cleaning = false;
        int initDir = curRobot.dir;

        for(int cnt =0; cnt < 4; cnt ++){
            int next_dir = (curRobot.dir - 1 < 0) ? (curRobot.dir + 3) : (curRobot.dir - 1);

            int next_y = curRobot.y + dir_y[next_dir];
            int next_x = curRobot.x + dir_x[next_dir];

            if(canRobotGo(next_y,next_x) == true){
                curRobot.y = next_y;
                curRobot.x = next_x;
                curRobot.dir = next_dir;
                cleaning = true;
                break;
            }
            else{
                if(next_dir == initDir){
                    break;
                }
                else{
                    curRobot.dir = next_dir;
                }
            }
        }

        if(cleaning == false){
            int next_y = curRobot.y - dir_y[initDir];
            int next_x = curRobot.x - dir_x[initDir];
            if(map[next_y][next_x]==WALL){
                break;
            }
            else{
                curRobot.y = next_y;
                curRobot.x = next_x;
                curRobot.dir = initDir;
            }
        }
        
    }

}

int main(){
    Coord robot(0,0,0);
    scanf("%d %d",&N,&M);

    scanf("%d %d %d",&robot.y,&robot.x, &robot.dir);
    for(int y = 0; y< N; y++){
        for(int x =0; x < M ; x++){
            scanf("%d",&map[y][x]);
        }
    }
    
    StartCleaning(robot);
    printf("%d\n",ans);
    return 0;
}