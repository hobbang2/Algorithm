#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    int days = (int)prices.size();
    vector<int> answer(days,0);

    for(int idx = 0 ; idx < days; idx++){
        for(int idx2 = idx + 1 ; idx2 < days;idx2++){
            answer[idx]++;
            if(prices[idx2] < prices[idx]){
                break;
            }
        }
    }
    return answer;
}