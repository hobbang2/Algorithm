# Union-Find
## 개요
서로소 집합(Distjoint-Set) 알고리즘  
여러 개의 노드 중에서 `두 개의 노드`를 선택해서 현재 이 두 노드가 `서로 같은 그래프에 속하는지` 판별하는 알고리즘  
각 노드의 root 노드를 기록하는 배열을 두고 갱신한다.  
만약, `1번 2번`, `2번 3번` 노드를 연결한다면 `1번 2번 3번` 노드는 하나의 그래프에 속한다.  
이 때, 3번 노드의 root 노드는 2로 기록되지만, 다시 1로 갱신해주는 것이 편리하다.  
`UNION-FIND`알고리즘을 이용해서 그래프에 cycle이 존재하는지를 판단할 수 있다.  

```cpp
int getParent(int target){
    if(rootArr[target] == target){
        return target;
    }
    else{
        return rootArr[target] = getParent(rootArr[target]);
    }
}
```


