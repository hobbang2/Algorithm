## [non-divisible-subset](https://www.hackerrank.com/challenges/non-divisible-subset/problem)
### 풀이
- 집합 S의 크기가 10만, 원소의 값이 최대 10억
- 나머지 연산을 이용하자!_! 
- 집합 S의 `부분 집합` 중에서 임의의 두 원소의 합이 `k`로 나누어 떨어지지 않는 것 중 가장 길이가 긴거 찾기
### 예시 
```
4 3
1 7 2 4
```
> 1+7 = 8, 8%3 = 2  
((1%3)+(7%3)) = 2  
=> 나머지 연산한 것의 합이 k가 되지 않는 것들끼리 모이자ㅏㅏㅏㅏ  

```cpp
// 나머지 연산 후 두 개 더해서 k랑 같아지면 나누어떨어지는 거
int nonDivisibleSubset(int k, vector<int> s) {
    int maxLen = 0;
    int sSize =(int) s.size();
    vector <int> remainder(k,0);
    for(int sIdx = 0 ; sIdx < sSize; sIdx++){
        remainder[s[sIdx]%k]+=1;
    }
    // 나머지가 0인 원소는 어디에 끼워넣어도 두 개 합이 0이 될 수 없으니까 ~_~ 
    maxLen = (remainder[0]==0)?0:1;
    for(int idx = 1; idx <= k/2;idx++){
        // 24행과 마찬가지로~_~ 
        if(idx == (k-idx)){
            continue;
        }
        // k-idx+idx = k 이니까 둘 중에 하나만 골라야함
        maxLen += (remainder[idx]>remainder[k-idx])?(remainder[idx]):(remainder[k-idx]);
    }
    maxLen += (k%2==0)?1:0;
    return maxLen;
}

```