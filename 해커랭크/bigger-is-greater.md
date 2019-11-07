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
![image](https://www.nayuki.io/res/next-lexicographical-permutation-algorithm/next-permutation-algorithm.svg

> The key observation in this algorithm is that when we want to compute the next permutation, we must “increase” the sequence as little as possible. 

```
예시 : (0, 1, 2, 5, 3, 3, 0) 
```
- 주어진 수열에서 `0,1,2,5` 까지는 숫자가 증가하는 형태
- 3번째 index 부터는 `5,3,3,0` 으로 숫자가 감소하는 형태 

> 1. 수열의 마지막 숫자부터 보면서 `증가`에서 `감소`로 넘어가는 index를 찾는다..   
2. 찾은 index가 0이면 마지막 permutation까지 찾은 것이므로 종료
3. 다시 수열의 마지막 숫자부터 보면서 1번에서 찾은 index에 위치하는 숫자보다 큰 것을 찾는다.   
4. 1번과 3번의 것을 swap한다.  
5. 1번 index 뒷 부분을 정렬

```java
boolean nextPermutation(int[] array) {
    // Find longest non-increasing suffix
    int i = array.length - 1;
    while (i > 0 && array[i - 1] >= array[i])
        i--;
    // Now i is the head index of the suffix
    
    // Are we at the last permutation already?
    if (i <= 0)
        return false;
    
    // Let array[i - 1] be the pivot
    // Find rightmost element that exceeds the pivot
    int j = array.length - 1;
    while (array[j] <= array[i - 1])
        j--;
    // Now the value array[j] will become the new pivot
    // Assertion: j >= i
    
    // Swap the pivot with j
    int temp = array[i - 1];
    array[i - 1] = array[j];
    array[j] = temp;
    
    // Reverse the suffix
    j = array.length - 1;
    while (i < j) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }
    
    // Successfully computed the next permutation
    return true;
}
```