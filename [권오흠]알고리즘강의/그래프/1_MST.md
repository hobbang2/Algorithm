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
## []()
