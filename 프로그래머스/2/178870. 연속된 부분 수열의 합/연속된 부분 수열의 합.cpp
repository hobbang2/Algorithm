#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0, 1000001};
    
    int s = 0 ; int e = -1 ;
    int sequenceSize = static_cast <int> (sequence.size());
    
    int curSum = 0;
    
    
    while((e < sequenceSize)){
        
        if(curSum > k){
            curSum -= sequence[s++];
        }
        else if(curSum == k){
            
            int curInterSize = answer[1] - answer[0];
            int tmpInterSize = e - s; 
            
            if(tmpInterSize < curInterSize){
                answer[0] = s; 
                answer[1] = e;
            }
            
            curSum -= sequence[s++];
        }
        else{
            ++e;
            curSum += sequence[e];
            
        }
        
        
    }
    
    
    return answer;
}