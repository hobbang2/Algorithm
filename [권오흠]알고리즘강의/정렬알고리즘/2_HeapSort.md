[참고강의 바로가기](https://bit.ly/2Q1yh1y)
~~HeapSort는 개인적으로 너무 복잡하고 어렵게 느껴지는 알고리즘ㅠㅠ~~ 

HeapSort는 `heap` 또는 `binary heap` 이라는 자료구조를 이용하는 정렬 알고리즘입니다.

HeapSort의 시간복잡도는 이전 시간에 배운 MergeSort와 똑같은 O(nlogn)이지만,

MergeSort는 추가 배열이 필요하고 Heap Sort는 그렇지 않다는 것이 큰 차이점입니다. 

그럼, heap을 정의 해봅시다. 

### Heap의 정의
- heap은 `complete binary tree` 이면서 

![complete](https://github.com/hobbang2/Algorithm/blob/master/%5B권오흠%5D알고리즘강의/정렬알고리즘/notes/full_complete.JPG)

full binary tree는 각 level 마다 모든 노드가 가득 차 있어야 합니다.

complete binary tree는 마지막 level의 자식 노드가 비어있어도 되는데, **오른쪽부터** 비어야한다는 조건이 있습니다.

따라서 full binary tree -> complete binary tree 이지만, **역은 성립하지 않습니다.**

- `heap property`를 만족 해야한다.

heap property란, 부모가 자식보다 크거나 같거나(max heap property) 부모가 자식보다 작거나 같은(min heap property) 성질을 뜻합니다.

node가 삽입되거나 삭제되는 경우가 발생하더라도 위의 두가지 조건은 반드시 성립해야 합니다.

여기서 질문, 동일한 data를 가진 heap은 유일할까요 ? 

### heap 표현하기
설명만 보면 heap은 구현하기 대단히 어려워보이지만, 사실은 일차원 배열로 충분히 구현할 수 있습니다. 

배열의 index로 부모와 자식노드를 표현할 수 있기 때문이지요.

- A[i]이 부모 = A[i/2]
- A[i]의 왼쪽 자식 = A[2*i]
- A[i]의 오른족 자식 = A[2*i+1]

앗, 그러면 heap을 유지하기 위한 overhead가 발생하지 않을까요 ? 

다행히도 heap은 complete binary tree이기 때문에 괜찮습니다 ! ~~WoW~~

하지만, node가 추가되고 삭제될 때에도 heap의 조건 두가지는 만족되어야합니다. 

이를 위해 기본 연산인 MAX_HEAPIFY가 필요합니다 ! 

### HEAPIFY 연산에 관하여 
HEAPIFY를 설명하기 앞서, 전제조건이 있습니다.
- 현재 tree의 전체 모양은 `complete binary tree` 입니다.
- tree의 왼쪽/오른쪽 sub tree는 왼쪽/오른쪽 자식을 root로 하는 tree입니다.
- 각각의 subtree는 모두 그 자체로 heap입니다.
- 즉, root node만이 유일하게 heap property를 만족하지 않습니다. (root node value가 자식의 value 보다 작습니다.)

이제 이 heap을 max heap으로 만들어봅시다!

#### 가장 간단한 방법
root node의 자식 node 중 root node 보다 값이 큰 것을 root node로 올려보내면 됩니다.

이렇게 하면 이긴 쪽(값이 큰 node)과 진 쪽(값이 작은 node)이 생기는데, 진 쪽은 변화가 없으니 그대로 heap을 유지하고 있습니다.

하지만 이긴 쪽은 다시 heap이 아니게 되므로 처음 과정을 반복해줍니다. 

이렇게 반복, 반복, 반복 하다가 더이상 비교할 자식이 없으면 종료합니다. 

근본적으로 `recursion`이 되겠네요 !!

그렇다면 HEAPIFY 알고리즘의 시간복잡도는 얼마일까요?

- heapify는 자식 중에 더 큰 값을 골라서 자기보다 크면 바꾼 후 다시 heapify 연산을 수행합니다.
- 따라서, heapify 알고리즘의 시간복잡도는 어떤 경우에도 tree의 높이보다 크지 않겠지요.
- 노드의 개수가 n인 heap에서 시간복잡도는 O(log h), h = theta(log n) 

### Heap을 이용해서 정렬하기
이제 heap을 이용해서 정렬된 data를 얻어봅시다. 

data는 아마도 linear한 형태로 들어올 것입니다. 

따라서 그 자체로 complete binary tree가 됩니다. :> 

> complete binary tree를 heap으로 !

이제 heap으로 만들어줄 차례입니다. 어떻게 하면 좋을까요?

힌트는 **node가 하나인 binary tree는 항상 heap**이라는 사실입니다.

자, 이제 node들을 level order의 역순으로 봐볼까요?

처음으로 leaf node가 아닌 첫번째 node를 찾아봅시다. 

이 node를 root로 하는 sub tree를 한 번 볼까요 ? 

당연하게도 이 sub tree의 sub tree(..)들은 node가 하나일테고 node가 하나인 binary tree는 항상 heap이므로 

이 sub tree는 heapify 연산할 조건을 만족했습니다! 

```
[BUILD-MAX-HEAP(A)]
heap-size[A] <- length[A]
for i <- [length[A]/2] downto 1
    do MAX-HEAPIFY(A,i)
=> O(N)
```
우리는 마지막 node(index =n)에서 시작하여 처음으로 leaf node가 아닌 node에서부터 heapify를 시작했습니다.

그러면 heapify를 시작하는 node의 index는 무엇일까요 ?  => ceiling(n/2)
