#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    
    vector<int> answer;
    map <string, int> pocketMap;
    
    for(vector<string>::iterator it = gems.begin(); it != gems.end(); ++it){
        pocketMap[*it] = 0;
    }
    
    int gemCnt = pocketMap.size();
    int startIdx = 0; int endIdx = 0;
    
    int cpyGemCnt = gemCnt;
    int partLen = 100002;
    
    while((startIdx <= endIdx) && ( endIdx < gems.size())){

        const string& curGem = gems[endIdx];
        int & curCnt = pocketMap[curGem];

        // 현재 보석이 주머니에 없음
        // 새로운 종류의 보석
        if(curCnt == 0){
            --cpyGemCnt;
        }
        
        curCnt += 1;

        // 모든 종류의 보석을 수집했으면 startIdx를 옮겨줌
        while(cpyGemCnt <= 0){
            int curPartLen = endIdx - startIdx;
            
            // 현재 구간이 더 짧으면 갱신
            if(partLen > curPartLen){
                partLen = curPartLen;
                answer = {startIdx + 1, endIdx + 1};
            }
            
            // startIdx 위치의 보석을 주머니에서 빼자.
            const string & prevGem = gems[startIdx];
            int & prevCnt = pocketMap[prevGem];
            prevCnt -= 1;
            // prevCnt가 0이 되면 주머니에 해당 보석이 없음
            cpyGemCnt += (prevCnt == 0);
            // startIdx 옮기기 
            ++startIdx;
        }
        endIdx += 1;
    }
    
    
    // gems에 있는 unique한 보석 이름을 찾아야 함 
    return answer;
}