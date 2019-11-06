## [Organizing Containers of Balls](https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem)
### 풀이
- `최대 100개` `최소 1개`의 컨테이너와 서로 다른 색의 공
- 컨테이너에 담긴 각 공의 개수는 `최소 0개` `최대 10억개`
- `조건 : ` 하나의 컨테이너가 하나의 타입의 공을 담도록 swap swap 하자 ! 
- 컨테이너에 담긴 공의 총 개수 == 타입별 공의 개수 이면 몇 번의 교환을 거쳐 조건을 만족시킬 수 있다. `Possible`
### 예시 
```
2
2
1 1
1 1
2
0 2
1 1
```
```
2
3
1 3 1
2 1 2
3 3 3
3
0 2 1
1 1 1
2 0 0
```
### 참고자료 : vector::clear
> vector 에 담긴 모든 원소를 삭제하고 container의 크기를 0으로 만든다.  
container의 크기를 유지하고 싶으면 `vector<T>().swap(x);   // clear x reallocating ` 을 쓰자. 
```cpp
string organizingContainers(vector<vector<int>> container) {
    for(int _n = 0; _n < n; _n++){
        if(containerSize[_n]!= numOfBalls[_n]){
            return "Impossible";
        }
    }
    return "Possible";
}

```