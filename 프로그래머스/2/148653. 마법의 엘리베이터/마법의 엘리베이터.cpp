#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    int curvalue = storey;
    
    while(curvalue > 0){
        int remain = curvalue % 10;
        
        if(remain > 5){
            int diff = 10 - remain;
            answer += diff;
            curvalue += diff;
        }
        else if(remain == 5){
            // 다음 자리의 숫자 확인 후 올라갈지 내려갈지 결정
            int nextRemainValue = (curvalue / 10 ) % 10;
            if(nextRemainValue + 1 > 5){
                answer += 5;
                curvalue += 5;
            }
            else{
                answer += 5;
                curvalue -= 5;
            }
        }
        else{
            answer += remain;
            curvalue -= remain;
        }
        
        curvalue /= 10;
    }
    
    return answer;
}