
## [The Grid Search]](https://www.hackerrank.com/challenges/the-grid-search/problem)
### 풀이
- 2차원 숫자 배열과 패턴이 주어진다. 
- 주어진 배열에서 패턴을 찾을 수 있으면 YES 아니면 NO
- 최대 1000 x 1000
- string 생성자를 이용하여 문자열로 비교해주었다. 
- `isInRange(int y , int x)`에서 범위 비교를 잘못해주어 틀렸음 

### 예제
```
2
10 10
7283455864
6731158619
8988242643
3830589324
2229505813
5633845374
6473530293
7053106601
0834282956
4607924137
3 4
9505
3845
3530
15 15
400453592126560
114213133098692
474386082879648
522356951189169
887109450487496
252802633388782
502771484966748
075975207693780
511799789562806
404007454272504
549043809916080
962410809534811
445893523733475
768705303214174
650629270887160
2 2
99
99

YES
NO
```
```cpp
int Y,X;
bool isInRange(int y, int x){
    // 주의하자 
    if((y <=Y )&&( x <=X)){
        return true;
    }
    return false;
}

// Complete the gridSearch function below.
string gridSearch(vector<string> G, vector<string> P) {
    Y = G.size();
    X=  G[0].size();
    int patternY = P.size();
    int patternX = P[0].size();
    
    for(int idx = 0 ; idx < Y*X; idx++){
        int curY = idx / X;
        int curX = idx % X;
        bool noAns = false;
        if(isInRange(curY+patternY, curX+patternX)==true){
            for(int y = curY; y < curY+patternY; y++){
                string tmpStr = string(G[y].begin()+curX,G[y].be gin()+curX+patternX);
                if(tmpStr.compare(P[y-curY])!=0){
                    noAns = true;
                    break;
                }
            }
            if(noAns == false){
                return "YES";
            }
        }
    }
    return "NO";
}
```

> string constructor 의 시간 복잡도는 특정되지 않았지만 일반적으로 문자열의 길이에 비례