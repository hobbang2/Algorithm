#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(vector<int> routeA, vector<int> routeB){
    
    // 진출 기준으로 정렬
    return routeA[1] < routeB[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    // 1. 진입 위치 기준으로 정렬
    sort(routes.begin(), routes.end(), comp);
    int routeSize = static_cast <int> (routes.size());
    int cameralocation = routes[0][1];
    ++answer;
    // 2. 
    for(int idx = 1 ; idx < routeSize ; ++idx){
        // 카메라의 위치가 다음 카메라의 진입점 보다 뒤에 있으면 진출점에 카메라 설치
        if(cameralocation < routes[idx][0]){
            cameralocation = routes[idx][1];
            ++answer;
        }
    }
    
    
    
    
    return answer;
}