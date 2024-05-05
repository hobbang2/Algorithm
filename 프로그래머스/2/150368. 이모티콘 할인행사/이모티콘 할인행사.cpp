#include <string>
#include <vector>

using namespace std;


typedef struct Result{
    int plus ;
    int salesMount ;
    
    Result(int _p = 0, int _s = 0){
        plus = _p;
        salesMount = _s;
        
    }
    
    bool const operator > (const Result & comp){
        if(plus == comp.plus){
            return salesMount  > comp.salesMount;
        }
        return plus > comp.plus;
    }
}Result;

Result result;

// 할인율은 10%, 20%, 30%, 40% 중 하나로 설정됩니다.
int discountRatio[4] = {10, 20, 30, 40};

Result calByCurCondition(const vector<vector<int>> & users,
                               const vector<int> & emoticons,
                               const string & curDiscountRatio){
    Result retValue;
    int emoticonNum = emoticons.size();
    int userNum = users.size();
    vector <int> tmpTotalVal(userNum, 0 );
    
    // for(const auto c :curDiscountRatio){
    for(int eidx = 0 ; eidx < emoticonNum ;++eidx){
        char c = curDiscountRatio[eidx];
        int curDiscountValue =  discountRatio[c-'0'];
        
        for(int uidx = 0 ; uidx < userNum; ++uidx){

            if(users[uidx][0] > curDiscountValue){
                // 안삼
                continue;
            }
            // 이모티콘 플러스 구매자
            if(-1 == tmpTotalVal[uidx]){
                continue;
            }
            
            int nextValue = tmpTotalVal[uidx] + emoticons[eidx] * (1 - (curDiscountValue / 100.0));
            
            if(users[uidx][1] <= nextValue){
                // 이모티콘 플러스 구매
                tmpTotalVal[uidx] = -1;
                retValue.plus += 1;
                continue;
            }
            tmpTotalVal[uidx] = nextValue;
        }
    }
    
    for(int uidx = 0 ; uidx < userNum ; ++uidx){
        
        if(-1 == tmpTotalVal[uidx]){
            continue;
        }
        retValue.salesMount += tmpTotalVal[uidx];
    }
    
    return retValue;
}

void dfs(const vector<vector<int>> & users,
         const vector<int> & emoticons,   
         string applyDiscountRatio){
    
    int emoticonNum = emoticons.size();
    
    if(emoticonNum == applyDiscountRatio.size()){
        Result curResult = calByCurCondition(users, emoticons, applyDiscountRatio);
        if(curResult > result){
            result = curResult;
        }
        
        return;
    }
    
    for(int eidx = 0 ; eidx < 4; ++eidx){
        dfs(users, emoticons, applyDiscountRatio + to_string(eidx));
    }
    return;
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    dfs(users, emoticons, "");
    answer = {result.plus, result.salesMount};
    return answer;
}