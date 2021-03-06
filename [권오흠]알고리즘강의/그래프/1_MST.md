# MST(Minimum Spanning Tree)
## Graph 요약 
- G(V,E) 
- Vertex(정점)집합과 Edge(간선)집합에 의해 정의됨 
- object들 간의 이진관계를 표현하는 structure
## [15-1강 : MST 개요](https://www.youtube.com/watch?v=i4ZDgJS0_yM&list=PL52K_8WQO5oUuH06MLOrah4h05TZ4n38l&index=34)
### 예제
- `입력` : n개의 도시 중 두 개의 도시를 연결하는 도로를 건설하는 비용
- `문제` : `최소 비용`으로 모든 도시들을 서로 연결하자. 
--------
- `가정` : `무방향 가중치` 그래프, 가중치는 모두 `양수`
### MST 문제 정의 
- 모든 노드들이 서로 연결되도록 하면서 가중치의 합이 최소가 되는 edge들의 부분 집합을 찾는 문제 
- `유일해`를 가지지는 `않음`
### 왜 Minimum Spanning `Tree`인가 ? 
- `Tree` : Cycle이 없는 연결된 무방향 그래프 // n개의 노드를 가지는 트리는 항상 n-1개의 엣지를 가짐  
### Generic MST 알고리즘
- Kruskal & Prim Algorithm이 `공통적`으로 가지는 구조
- 어떤 MST의 부분집합 a에 대해 $A \union {(u,v)}$ 도 어떤 MST의 부분집합이 된다 => edge(u,v)는 A에 대해 안전하다.
```
- 1. A = $\emptyset$
- 2. 집합 A에 대해 `안전한` edge를 찾아 A에 더한다.
- 3. 엣지의 개수가 `n-1개`가 될 때 까지 2를 반복
```
#### 안전한 edge 찾기
- `cut` : 그래프의 정점들을 두 개의 집합 S와 V-S로 분할한 것
- `cross` : edge (u,v)에 대해 u가 S에 속하고 v가 V-S에 속할 때, edge(u,v)는 cut(S,V-S)를 크로스한다.
- `respect` : edge들의 부분집합 A에 속한 어떤 edge도 cut(S,V-S)를 `cross`하지 않을 때, cut(S,V-S)는 A를 존중한다.
> `cut` : 노드들을 두 그룹으로 분할한 것  
 `cross` : cut을 가로지르는 edge  
 `respect` : edge집합 A에 속한 어떤 edge도 cut을 cross 하지 않을 때

### 정리
A가 어떤 MST의 부분집합이고, (S,V-S)는 edge 집합 A에 의해 respect된다고 하자 !  
그러면, 이 cut을 cross하는 edge들 중 `가장 가중치가 작은 edge(u,v)`는 A에 대해 `안전`하다 ^_^  
> `증명은 36'`
## [15-2강 : Kruskal 개요](https://www.youtube.com/watch?v=Z_ug3JRxu2s&list=PL52K_8WQO5oUuH06MLOrah4h05TZ4n38l&index=35)
### Kruskal Algorithm
> 1. edge들을 `가중치의 오름차순`으로 정렬  
> 2. 이미 선택된 edge들과 `cycle을 형성하지 않는` edge들을 순서대로 선택  
> 3. `n-1`개의 edge가 선택되면 종료  
### 왜 MST가 찾아질까?
> `7'~12'`
### 구현 : Cycle 검사 
- 어떤 edge 를 추가했을 때 cycle이 생기지는 않는지를 판단해야한다 ! 
- 각각의 연결 요소들을 `하나의 집합`으로 표현  
- 어떤 두 노드를 연결하려는데, 두 노드가 같은 집합에 속하는 원소이면 ? 연결 시 cycle을 형성하게 된다 ! 
> 1. `초기상태` : 각각의 node들을 `하나의 집합`으로 표현  
> 2. `가중치가 가장 작은 edge 선택하기`
> 3. 선택된 edge로 연결된 두 node가 같은 집합에 속해있다면 cycle이 형성되므로 bye bye  
> 4. 아니라면, `UNION` : 하나의 집합으로 만들어준다.  

> 슈도코드 `22'26''`  
 
## [15-3강 : Kruskal 구현](https://www.youtube.com/watch?v=_ocho3EzDH4&list=PL52K_8WQO5oUuH06MLOrah4h05TZ4n38l&index=36)
`가장 적은 비용`으로 `모든 노드`를 연결한다!_!  
- `edge`들을 weight가 작은 것부터 큰 것을 순서대로 보면서  
- 어떤 edge `u`,`v`에 대해 서로 속한 집합이 다른지 // 사이클을 만드는지 검사  
- 사이클을 형성하지 않으면 `u` union `v`  

> Find algorithm 은 tree의 높이에 비례하는 시간 복잡도를 가진다.  
=> Weighted Union : 두 개의 tree를 union 할 때 작은 tree의 root를 큰 tree의 root의 자식으로 만들자!  
// 각 tree의 노드의 수를 counting 하고 있어야한다 ^_^  
=> node의 수가 N개 일 때, 이 tree의 level의 maximum 값은 `log N`  

> Path Compression : Find 할 때  
```cpp
// FIND-SET-PC(x)
while x != p[x] do
    p[x] <- p[p[x]];
    x <- p[x];
end.
return p[x];
```

> WUPC(Weight Union & Path Compression) - M번의 union-find 연산의 총 시간복잡도는 O(N+Mlog*N)  
log*N = (log log log log...logN)  
log*N = N에 log를 몇 번 취하면 1이 되는지에 대한 횟수 ! 

> 예)  
N이 4이면 log*4 = 2  
N이 16이면 log*16 = 3  
log*N이 4가 되려면 N은 2^16  
log*N이 5보다 커질 일은 없을거셈 !  
왜냐하면 log*N = 5이려면 N= 2^65536  

> kruskal Algorithm : O(|E|log|E|)  정렬 알고리즘의 시간복잡도에 의해 결정됨 !  
// 노드가 n 개 일 때 edge의 수 |E|는 최대 (n)(n-1)/2 개  
따라서 시간 복잡도는 `O(NlogN)`  

```
Initial A : O(1)  
First for loop : |V| make-sets  
sort E : O(|E|log|E|)  
second for loop : O(|E|) FIND-SETs and UNIONs  
```

// 밀도가 높은 그래프에 적절합니당
## [15-4강 : Prim의 알고리즘](https://www.youtube.com/watch?v=n9kjPc_W_rc&list=PL52K_8WQO5oUuH06MLOrah4h05TZ4n38l&index=37)
- `임의의 노드`를 출발노드로 선택  
- `출발 노드`를 포함하는 트리를 점점 키워가자. 
- 매 단계에서 `이미 포함된 노드`와 `포함되지 않은 노드`를 연결하는 에지들 중 가장 가중치가 `작은` 에지를 선택
- 모든 노드들이 연결되면 알고리즘 종료 ^_^ 

### 왜 MST 가 찾아지는가 ? 
> [7'49''](https://youtu.be/n9kjPc_W_rc?list=PL52K_8WQO5oUuH06MLOrah4h05TZ4n38l&t=483)

### 어떻게 구현할 것인가 ? 
> `이미 포함된 노드`와 `포함되지 않은 노드`를 연결하는 에지들 중 가장 가중치가 `작은` 에지를 찾는 것이 중요!  
에지를 찾는 데에 최악의 경우 O(N^2)  
아무 생각없이 구현하면 Prim의 알고리즘은 O(N^3)  

> 가중치가 최소인 에지 찾기  

- Va : 이미 트리에 포함된 노드들  
- Va에 아직 속하지 않은 `각 노드` v에 대해 다음과 같은 값을 유지하자.  
    + key(v) : 이미 Va에 속한 노드와 자신을 연결하는 에지들 중 가중치가 최소인 에지 (u,v)의 가중치  
    + pi(v) : 그 에지 (u,v)의 끝점 u  
key값이 최소인 것을 찾아서 연결하면 됨 !//O(N)  

> key값을 계산하는 데에 걸리는 시간은 얼마일까 ?  
- 필요한 key값을 갱신만 해주면 된다. // 새로 Va에 속하게 된 노드와 연결된 것들만 갱신하면 됨.  
- O(N)

=> 1 step : O(N) , (n-1) * O(N) = O (N^2)  

// 인접행렬이나 인접리스트에 관계없이 O(n^2)
```cpp
MST-Prim(G,w,r) : O(N^2)
  for each u in V do
      key[u]<- inf
      pi[u] <- NIL
  end
  Va <- {r}
  key[r] <- 0
  // n-1 번 반복합니다. 
  while `|Va| < n` do
  // 최소값 찾기 O(N) 
      find u not in Va with the `minimum key` value;
      Va <- Va union {u}
  // degree(u) = O(N)
      for each v not in Va adjacent to u do
          if `key[v] > w(u,v)` then
              key[v] <- w(u,v) then
              pi[v] <- u
          end.
      end.
  end.
```

> 효과적인 Prim의 알고리즘 구현을 위해서는 !?  
- `최소 우선순위 큐`를 이용하자. 
- V-Va에 속한 노드들을 저장  
- `Extract-Min` : key값이 최소인 노드를 삭제 후 반환  

```cpp
MST-PRIM(G,w,r) : O(mlogN)
  for each u in V[G]
      do key[u] <- INF
         pi[u] <- NIL
  key[r] <- 0
  // 시작 노드의 값을 먼저 하나 넣어줌 
  Q <- V[G]
  while Q is not empty set
      do u <- EXTRACT-MIN(Q)
          for each v in Adj[u]
              do if v in Q and w(u,v) < key[v]
                  then pi[v] <- u
  // key 값을 update 한다 
  // heap은 data의 크기에 관한 조건을 만족해야하므로 heapify 연산이 필요함 
  // O(logN) , 전체는 sum of deree of (V) = m 번 실행된다
                      key[v] <- w(u,v)
```
- Fibonacci 힙을 사용하면 O(m+NlogN)에 구현 할 수 있다.  
