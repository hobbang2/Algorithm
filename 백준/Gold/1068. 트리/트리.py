import sys 
sys.setrecursionlimit(10 ** 7)

N = int(input())
parents = list(map(int, input().split(' ')))
remove_node = int(input())

def remove_parents(target_parent:int):
    global parents

    if(target_parent < 0):
        return
    
    parents[target_parent] = -2

    # 지우려는 값을 부모로 가진 것들을 모두 찾아서 지워준다.
    for idx, p in enumerate(parents):
        if(p == target_parent):
            parents[idx] = -2
            remove_parents(idx)

remove_parents(remove_node)

# 어떤 노드의 부모 노드는 리프 노드 일 수 없음
result = 0 
for idx in range(N):
    if((parents[idx] > -2) and (idx not in parents)):
        result += 1

print(result)