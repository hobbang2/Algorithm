## [The Time in Words](https://www.hackerrank.com/challenges/the-time-in-words/problem)
### 풀이
- 5:01 -> one `minute` past five
- 5:30 -> half past five
- 5:47 -> thirteen minutes to six
- 6:45 -> quarter to six
- 9:00 -> nine o' clock

> if 문 떡칠 보다는 노가다가 좀 더 예쁜거 같다. 
```
vector<string> numbers = {
        "zero", 
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
        "twenty",
        "twenty one",
        "twenty two",
        "twenty three",
        "twenty four",
        "twenty five",
        "twenty six",
        "twenty seven",
        "twenty eight",
        "twenty nine"
    };

    written by rorua in hackkerank
```
### 코드
```cpp

string hour[13] = {"","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve"};
string minute[13] = {"ten","eleven","twelve","thirteen","fourteen","quarter","sixteen","seventeen","eighteen","nineteen"};
// Complete the timeInWords function below.
string findSubWord(int m){
    string subWord = "";
    if(m == 1){
        subWord+="one minute ";
    }
    else if((m/10) == 2){
        subWord+="twenty "+hour[m%20];
    }
    else if((m / 10) == 1){
        subWord+= minute[m%10];
    }
    else{
        subWord+= hour[m];
    }
    if((m!=20)&&(m!=1))
        subWord += ((m!=15))?" minutes ":" ";
    return subWord;
}
string timeInWords(int h, int m) {
    string ans = "";
    ans+=hour[h];
    if(m == 0){
        ans += " o\' clock";
    }
    else if(m <=30){
        string subWord = "";
        subWord+=(m==30)?("half "):(findSubWord(m));
        subWord += "past "+ans;
        ans = subWord;
    }
    else{
        m = 60-m;
        string subWord = findSubWord(m);
        subWord += "to "+hour[h+1];
        ans = subWord;
    }
    return ans;
}

```
### [Reference: Next lexicographical permutation algorithm](https://www.nayuki.io/page/next-lexicographical-permutation-algorithm)
[](https://www.nayuki.io/res/next-lexicographical-permutation-algorithm/next-permutation-algorithm.svg

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