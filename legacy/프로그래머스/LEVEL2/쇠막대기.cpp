#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    char lastBrace = arrangement[0];
    
    int lenOfString = arrangement.size();
    vector <char> storeBrace;

    int numOfStick = 0;

    for(int idx = 0 ;idx < lenOfString; idx++){

        if(arrangement[idx] == '('){
            storeBrace.push_back(arrangement[idx]);
            numOfStick++;
        }
        else{
            // '(' , ')'
            if(lastBrace == '(' && arrangement[idx] == ')'){
                // 레이저니까 쇠막대수에서 빼주어야 한다. 
                numOfStick--;
                answer += numOfStick;
            }
            // ')',')'
            else if(lastBrace == ')' && arrangement[idx] == ')'){
                // 쇠막대가 끝난거니까 쇠막대 하나 없애주고 꽁다리는 더해주기
                numOfStick--;
                answer++;
            }
            storeBrace.pop_back();
        }
        lastBrace = arrangement[idx];
    }
    return answer;
}