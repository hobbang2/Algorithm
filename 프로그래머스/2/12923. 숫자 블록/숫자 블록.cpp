#include <string>
#include <vector>
#include <cmath>

using namespace std;

int getDivisor(long long num){
    long long maxRange = sqrt(num);
    int maxDiv = 1;
    for(long long div = 2; div <= maxRange; ++div){
        // printf("%lld %lld % lld\n", num, div, (num / div));
        if((0 == (num % div))){
            if(( (num / div) <= 10000000 )){
                return int(num / div);
                
            }
            
            if(div <= 10000000 ){
                maxDiv = (maxDiv < div) ? div : maxDiv;
                
            }
        }
        // if( div > 10){
            // return 1;
        // }
    }
    return maxDiv;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    
    for(long long start = begin; start <= end; ++ start ){
        
        int curdiv = getDivisor(start);
        answer.push_back(curdiv);
    }
    
    if(begin == 1){
        answer[0] = 0;
    }
    
    return answer;
}