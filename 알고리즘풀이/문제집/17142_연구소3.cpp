#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

enum { PATH, WALL, VIRUS, ACTIVE = 9 };
typedef struct Virus {
   int y, x;
   Virus(int _y = 0, int _x = 0) :y(_y), x(_x) {
   }
}Virus;

// 북 남 서 동;
int dirY[4] = { -1,1,0,0 };
int dirX[4] = { 0,0,-1,1 };
int answer = 987654321;
int N, M;
vector <vector <int> > map(51, vector<int>(51, 0));
vector <Virus> virusVec;
vector <bool> check(11, false);

bool isInMap(int y, int x) {
   if (y <= 0 || x <= 0 || y > N || x > N) {
      return false;
   }
   return true;
}

bool isInMap(const Virus & v) {
   if (v.y <= 0 || v.x <= 0 || v.y > N || v.x > N) {
      return false;
   }
   return true;
}

bool canGo(int y, int x,vector <vector <int> > & cpyMap) {
   if ((cpyMap[y][x] == WALL)|| (cpyMap[y][x] == ACTIVE)) {
      return false;
   }
   return true;
}
bool isSwWinner(vector <vector <int> > & cpyMap) {
   for (int y = 1; y <= N; y++) {
      for (int x = 1; x <= N; x++) {
         if (cpyMap[y][x] == PATH) {
            return false;
         }
      }
   }
   return true;
}

void printMap(vector <vector <int> > & cpyMap) {
   for (int y = 1; y <= N; y++) {
      for (int x = 1; x <= N; x++) {
         printf("%d ", cpyMap[y][x]);
      }
      printf("\n");
   }
   printf("\n");
}

int spreadVirus(queue <Virus> & virusQ, vector <vector <int> > & cpyMap,int & numOfZero) {
   int curTime = 0;
   while (virusQ.empty() == false) {
      //printMap(cpyMap);
      if (numOfZero == 0) {
         break;
      }
      curTime += 1;
      if (curTime >= answer) {
         break;
      }
      int curSize = (int)virusQ.size();
      for (int s = 1; s <= curSize; s++) {
         Virus curVirus = virusQ.front(); virusQ.pop();
         for (int d = 0; d < 4; d++) {
            int nextY = curVirus.y + dirY[d];
            int nextX = curVirus.x + dirX[d];
            if ((isInMap(nextY, nextX) == true)&&(canGo(nextY,nextX,cpyMap)==true)) {
               numOfZero -= (cpyMap[nextY][nextX] == PATH);
               cpyMap[nextY][nextX] = ACTIVE;
               Virus nextVirus(nextY, nextX);
               virusQ.push(nextVirus);
            }
         }
      }
   }
   return curTime;
}


void swTime(int idx, int cnt, int numOfVirus,int originZero) {
   if ((idx > numOfVirus) || (cnt > M)) {
      return;
   }
   if (cnt == M) {
      // 최소시간 구하기
      vector <vector <int> > cpyMap = map;
      queue <Virus> virusQ;
      int numOfZero = originZero;
      for (int v = 1; v <= numOfVirus; v++) {
         if (check[v] == true) {
            Virus curVirus = virusVec[v];
            cpyMap[curVirus.y][curVirus.x] = ACTIVE;
            virusQ.push(virusVec[v]);
         }
      }
      int curTime = spreadVirus(virusQ, cpyMap,numOfZero);
      // 점령당함? 
      if (isSwWinner(cpyMap)==true) {
         answer = (answer > curTime) ? curTime : answer;
      }
   }
   check[idx] = true;
   swTime(idx + 1, cnt + 1, numOfVirus,originZero);
   check[idx] = false;
   swTime(idx + 1, cnt, numOfVirus,originZero);

}

int main() {
   virusVec.push_back(-1);
   scanf("%d %d", &N, &M);
   // map 입력받기 
   int numOfZero = 0;
   for (int y = 1; y <= N; y++) {
      for (int x = 1; x <= N; x++) {
         scanf("%d", &map[y][x]);
         if (map[y][x] == 2) {
            Virus curVirus(y, x);
            virusVec.push_back(curVirus);
         }
         if (map[y][x] == 0) {
            numOfZero+=1;
         }
      }
   }

   if (numOfZero != 0)
   {
      int numOfVirus = (int)virusVec.size();
      swTime(1, 0, numOfVirus,numOfZero);
      answer = (answer == 987654321) ? (-1) : (answer);
   }
   else {
      answer = 0;
   }
   printf("%d\n", answer);
   return 0;
}