#include <string>
#include <vector>
#include <utility>
#include <deque>

using namespace std;

void crossBridge(deque <pair <int,int> > & dq){
    for(int idx = 0; idx < (int)dq.size();idx++){
        dq[idx].second--;
    }
    return;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int numOfTruck = (int)truck_weights.size();
    deque <pair <int,int> > onBridge;

    int nextWeight = 0;
    int curWeight = 0;

    for(int idx = 0 ; idx < numOfTruck;){
        nextWeight = curWeight + truck_weights[idx];
        if(nextWeight <= weight){
            pair <int,int> curTruck(truck_weights[idx],bridge_length);
            onBridge.push_back(curTruck);

            crossBridge(onBridge);
            if(onBridge[0].second<=0){
                nextWeight -= onBridge[0].first;
                onBridge.pop_front();
            }

            curWeight = nextWeight;
            answer++;
            idx++;
        }
        else{
            answer++;
            crossBridge(onBridge);
            if(onBridge[0].second <= 0){
                curWeight -= onBridge[0].first;
                onBridge.pop_front();
            }
        }
    }

    while(onBridge.empty()==false){
        answer++;
        crossBridge(onBridge);
        if(onBridge[0].second <= 0){
            curWeight -= onBridge[0].first;
            onBridge.pop_front();
        }
    }

    return answer;
}