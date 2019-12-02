# Fibonacci Sequence
피보나치 수열에서 n번째 항은 n-1번째 항과 n-2번째 항의 합이다. 
n번째 항을 Fibo(n)이라고 정의하면, 초기항 Fibo(0)= 0, Fibo(1) = 1 이다. 

## Recursion

이를 `재귀 함수`로 구현하면 다음과 같다.
```cpp
long long fibo(long long n){
    if(n <= 1){
        return n;
    }
    else{
        return fibo(n-1)+fibo(n-2);
    }
}
```
n = 5 일 때, 
fibo(4)+fibo(3)이 호출되고 
fibo(4)는 fibo(3)+fibo(2)를 
fibo(3)은 fibo(2)+fibo(1)을 호출한다. 
n이 커질수록 중복 계산이 많아진다. 

## Memorization
중복을 줄이기 위한 방법으로는 `meorization`이 있다. 

```cpp
arr[0] = 0, arr[1] = 1;
long long fibo(long long n){
    if(arr[n] != -1){
        return arr[n];
    }
    else{
        return arr[n] = fibo(n-1)+fibo(n-2);
    }
}
```

## Pisano Period
피보나치 수는 `modulo n`(n은 자연수)에 대해 periodic하다. 
> 노트 필기 넣기 