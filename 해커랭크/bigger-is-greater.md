## [Bigger is Greater](https://www.hackerrank.com/challenges/bigger-is-greater/problem)
### 풀이
- 주어진 문자열에 나열된 문자들을 조합하여 주어진 문자열 보다 큰 것 찾기 
- `크다` : 사전 순으로 나열하였을 때 뒤에 위치한다. 
- next_permutation으로 현재 조합 순서 다음 것을 찾아주기 
- 없으면 `no answer`
- 문자열 길이 최대 100, 테스트케이스 최대 10만개 
### 예시 
```
lmno
dcba
```
```
lmon
no answer
```
### 코드
```cpp
string biggerIsGreater(string w) {
    string ans = w;
    next_permutation(ans.begin(),ans.end());
    ans = (ans == w || ans < w) ? ("no answer"):ans;
    return ans;
}
```
### [Reference: Next lexicographical permutation algorithm](https://www.nayuki.io/page/next-lexicographical-permutation-algorithm)
[](https://www.nayuki.io/res/next-lexicographical-permutation-algorithm/next-permutation-algorithm.svg)
