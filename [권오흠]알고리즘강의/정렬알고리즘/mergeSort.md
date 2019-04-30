[참고강의 바로가기](https://www.youtube.com/watch?v=2YvFRAC8UTM&list=PL52K_8WQO5oUuH06MLOrah4h05TZ4n38l&index=10
)

MergeSort 는 devide and conquer 전략을 사용합니다. 

devide and conqure은 하나의 큰 문제를 작은 크기의 `동일한` 문제로 쪼개어 조금씩 정복해 나가는 것입니다. 

다시 정리하자면, 아래 세 단계를 거쳐 어떤 문제를 해결하는 방법을 devide and conquer 라고 합니다 .

- 분할 : 해결하고자 하는 문제를 '작은 크기의 동일한 문제'들로 분할 ★동일한★ 

- 정복 : 각각의 작은 문제를 순환적으로 해결 

- 합병 : 작은 문제의 해를 합하여(merge) 원래 문제에 대한 해를 구함

작은 크기의 동일한 문제들을 해결하는 것이므로 devide and conquer는 본질적으로 `recursion` 으로 구현됩니다. 

아래 필기에서 좌측이 알고리즘에 대한 전체적인 설명이고 

우측이 알고리즘을 조금 더 풀어서 기술한 것입니다. 

함수가 호출되면서 stack에 쌓이는 모습을 그려봤는데, 하나씩 따라가면서 이해하면 됩니다.

recursion의 base case 는 start >= end 입니다. // 리스트의 길이가 0이거나 1이면 종료

두 개의 리스트는 항상 정렬되어 있으므로 항상 맨 앞 부터 두 원소를 비교해나갑니다. 

둘 중에 작은 것을 여분의 배열에 담아줍니다. 

이렇게 어느 한 쪽이 끝날 때 까지 담고, 나머지 요소들을 모두 뒤에 담아줍니다. 

여분의 배열을 선언하는 방법에는 아래와 같은 두 방법이 있습니다. 

- 전역변수 선언 

- 함수 내 지역변수 선언 

어느 것을 선택하느냐에 따라 구현이 조금 달라집니다. 

![MergeSort](https://raw.githubusercontent.com/hobbang2/Algorithm/master/%5B%EA%B6%8C%EC%98%A4%ED%9D%A0%5D%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98%EA%B0%95%EC%9D%98/%EC%A0%95%EB%A0%AC%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/notes/mergeSort.jpg)
