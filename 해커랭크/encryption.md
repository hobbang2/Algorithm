## [Encryption](https://www.hackerrank.com/challenges/encryption/problem)
### 풀이
- 최대 길이가 `81`인 문자열 s가 주어진다. 
- s에서 공백을 제거한 것의 길이를 구해서 제곱근의 floor와 ceil을 구한다. 
- 압축한 문자열을 행렬 floor x ceil 에 나열
- 행렬의 각 열을 하나의 단어로 가지는 문장으로 만들어 출력
### 예시 
```
haveaniceday

have
anic
eday

hae and via ecy

```
### 참고자료 : vector::clear
> vector 에 담긴 모든 원소를 삭제하고 container의 크기를 0으로 만든다.  
container의 크기를 유지하고 싶으면 `vector<T>().swap(x);   // clear x reallocating ` 을 쓰자. 
```cpp
int idx = 0;
char compStr[82];
char map[10][10];
string encryption(string s) {
    for(int i=0; i <(int)s.size();i++){
        if(s[i] ==' '){
            continue;
        }
        compStr[idx++]=s[i];
    }
    int f = (int)floor(sqrt(idx));
    int c = (int)ceil(sqrt(idx));
    string tmpAns[10]={"",};
    for(int i =0 ; i <idx;i++){
        tmpAns[i%c]+=compStr[i];
    }
    string ans = "";
    for(int x = 0; x < c; x++){
        ans+=tmpAns[x]+" ";
    }
    return ans;
}

```