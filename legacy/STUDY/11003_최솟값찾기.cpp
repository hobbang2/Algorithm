#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
   int N=0, L=0;
   scanf("%d %d", &N, &L);
   deque <pair<int,int> > dq_min;

    // pair<int,int> : idx,value;

   for (int idx = 0; idx < N; idx++) {
      pair<int,int> curPair(0,0);
      curPair.first = idx;
      scanf("%d", &curPair.second);

      if(idx-L+1 > 0){
         while((dq_min.empty() == false) && (dq_min.front().first < idx-L+1)){
            dq_min.pop_front();
         }
      }

      while((dq_min.empty()==false) &&(dq_min.back().second > curPair.second)){
         dq_min.pop_back();
      }
      dq_min.push_back(curPair);
      printf("%d ",dq_min.front().second);
   }

   return 0;
}