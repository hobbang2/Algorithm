#include <string>
#include <vector>
#include <queue>

using namespace std;

const string DIA  = "diamond";
const string FE   = "iron";
const string ROCK = "stone";

typedef struct Treasure{
    
    int dia;
    int fe;
    int rock;
    
    Treasure(int _d = 0, int _f = 0, int _r = 0):dia(_d), fe(_f), rock(_r){};
    
    bool operator < (const Treasure & comp) const {
        if(dia == comp.dia){
            if(fe == comp.fe){
                return rock < comp.rock;
            }
            return fe < comp.fe;
        }
        return dia < comp.dia;
    }
}Treasure;

priority_queue<Treasure, vector<Treasure>, less<Treasure> > pq;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int mineralcnt = minerals.size();
    int totalPickCnt = 0;
    
    // 사용할 수 있는 곡괭이 총 개수
    for(auto p: picks){
        totalPickCnt += p;
    }
    
    for(int idx = 0 ; idx < mineralcnt; ){
        Treasure curTreasure;
        --totalPickCnt;
        // 곡괭이 수만큼만 채굴
        if(totalPickCnt < 0){
            break;
        }
        
        // 5개씩 묶음으로 저장
        int lastidx = idx + 5;
        for(; (idx < mineralcnt)&&(idx < lastidx ); ++idx){
            if(DIA == minerals[idx]){
                curTreasure.dia++;
            }
            else if(FE == minerals[idx]){
                curTreasure.fe++;
            }
            else if(ROCK == minerals[idx]){
                curTreasure.rock++;
            }
        }
        pq.push(curTreasure);
    }
    
    // 다이아몬드, 철, 돌 순으로 개수가 많을 때
    // 비용이 적게 드는 곡괭이 사용
    while(false == pq.empty()){
        Treasure curTreasure = pq.top(); pq.pop();
        
        // DIAMONT
        if(picks[0] > 0){
            --picks[0];
            answer += (curTreasure.dia + curTreasure.fe + curTreasure.rock);
        }
        // FE
        else if(picks[1] > 0){
            --picks[1];
            answer += (5 * curTreasure.dia + curTreasure.fe + curTreasure.rock);
        }
        // ROCK
        else {
            --picks[2];
            answer += (25 * curTreasure.dia + 5 * curTreasure.fe + curTreasure.rock);
        }
    }
    
    return answer;
}