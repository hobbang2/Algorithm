# [Dijkstra Algroithm](https://ko.wikipedia.org/wiki/%EB%8D%B0%EC%9D%B4%ED%81%AC%EC%8A%A4%ED%8A%B8%EB%9D%BC_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98)
![dijkstra Graphic](https://upload.wikimedia.org/wikipedia/commons/5/57/Dijkstra_Animation.gif)
## 정의 
- 두 꼭짓점 간의 `가장 짧은 경로`를 찾는 알고리즘
- `한 꼭짓점`으로부터 다른 `모든` 꼭짓점까지의 `최단경로`를 찾는 알고리즘 
- 최악의 경우 시간 복잡도는 `단순 탐색`의 경우 `O(N^2)`,
이진 탐색 트리나 이진 힙의 경우 `O((|E|+|V|)log|V|)`=>`O(|E|log|V|)`, 
`피보나치 힙`을 사용할 경우 `O(|E|+|V|log|V|)`

## 구현
[swea1249번 보급로](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15QRX6APsCFAYD)
1. 우선순위 큐와 구조체를 이용
2. 구조체의 operator를 재정의하는 방식으로 우선순위 큐를 사용 
#### 연산자 오버로딩
```cpp
typedef struct Coord {
	int y, x;
	int w;
	bool operator > (const Coord & c)const {
		return w > c.w;
	}
}Coord;
```
#### 다익스트라 알고리즘 
```cpp
void dijkstraAlg(int y, int x) {
	priority_queue<Coord, vector<Coord>, greater<Coord>> pq;
	pq.push({ 1,1,0 });
	int pqSize = 0;
	while (pq.empty() == false) {
		pqSize = pq.size();
		for (int idx = 1; idx <= pqSize; idx++) {
			Coord curCoord = pq.top(); pq.pop();
			if (curCoord.y == N && curCoord.x == N) {
				return;
			}
			for (int d = 0; d < 4; d++) {
				int nextY = curCoord.y + dirY[d];
				int nextX = curCoord.x + dirX[d];
				if (isInMap(nextY, nextX) == true) {
					int nextValue = curCoord.w+map[nextY][nextX];
					if (dist[nextY][nextX] > nextValue) {
						pq.push({ nextY,nextX,nextValue});
						dist[nextY][nextX] = nextValue;
					}
				}
			}
		}
	}
}
```
