#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;


vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> numStack;
    int arrSize = static_cast <int> (arr.size());
    
    for(int idx = 0 ; idx <  arrSize;  ++idx){
        if((false == numStack.empty()) &&
           ( arr[idx] == numStack.top())){
            numStack.pop();
        }
        numStack.push(arr[idx]);
    }
    
    while(false == numStack.empty()){
        answer.push_back(numStack.top());
        numStack.pop();
    }
    
    

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    reverse(answer.begin(), answer.end());
    return answer;
}