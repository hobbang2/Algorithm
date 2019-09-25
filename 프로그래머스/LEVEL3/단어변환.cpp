#include <string>
#include <vector>
#include <queue>
using namespace std;

vector <bool> visitCheck(51,false);
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue <string> wordQ;
    wordQ.push(begin);
    
    while(wordQ.empty()== false){
        int qSize = (int)wordQ.size();
        for(int idx = 0 ; idx < qSize ; idx++){
            string curWord = wordQ.front();wordQ.pop();
            // target 단어에 도달했으면 answer(depth)를 반환하기
            if(curWord.compare(target)==0){
                return answer;
            }

            else{
                for(int wordIdx = 0; wordIdx < (int)words.size();wordIdx++){
                    // depth가 더 작을 때 이미 살펴봤다면 건너뛰어도 괜찮다. 
                    if(visitCheck[wordIdx] == true){
                        continue;
                    }

                    int cnt = 0;
                    string tmpNext = words[wordIdx];
                    // 현재 단어와 한 글자 차이나는 것만 대상이 된다. 
                    // 이 정보를 이용하여 그래프를 만들어서 bfs와 dfs를 진행할 수도 있다. 
                    for(int _idx = 0; _idx < curWord.size();_idx++){
                        if(tmpNext[_idx]!=curWord[_idx]){
                            cnt = cnt+1;
                        }
                    }
                    if(cnt == 1){
                        wordQ.push(tmpNext);
                        visitCheck[wordIdx] = true;
                    }
                }
            }
        }
        answer = answer + 1;
    }
    return 0;
}