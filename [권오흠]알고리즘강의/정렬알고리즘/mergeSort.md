[참고강의 바로가기](https://www.youtube.com/watch?v=2YvFRAC8UTM&list=PL52K_8WQO5oUuH06MLOrah4h05TZ4n38l&index=10
)

MergeSort 는 devide and conquer 전략을 사용합니다. 

devide and conqure은 하나의 큰 문제를 작은 크기의 `동일한` 문제로 쪼개어 조금씩 정복해 나가는 것입니다. 

다시 정리하자면, 아래 세 단계를 거쳐 어떤 문제를 해결하는 방법을 devide and conquer 라고 합니다 .

- 분할 : 해결하고자 하는 문제를 '작은 크기의 동일한 문제'들로 분할 ★동일한★ 

- 정복 : 각각의 작은 문제를 순환적으로 해결 

- 합병 : 작은 문제의 해를 합하여(merge) 원래 문제에 대한 해를 구함

작은 크기의 동일한 문제들을 해결하는 것이므로 devide and conquer는 본질적으로 `recursion` 으로 구현됩니다. 

