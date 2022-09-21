#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int requireDays = ceil((100-progresses[0])/speeds[0]);
    int cnt = 1;
    int numOfProg = (int)progresses.size();

    for(int idx = 1; idx < numOfProg; idx++){
        int curRequire = (int)ceil((100-progresses[idx])/speeds[idx]);
        if(requireDays < curRequire){
            answer.push_back(cnt);
            requireDays = curRequire;
            cnt  = 1;
        }
        else{
            cnt = cnt + 1;
        }
    }
    answer.push_back(cnt);
    return answer;
}