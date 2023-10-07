from collections import deque
import sys 
input = sys.stdin.readline

HEIGHT, CNT = 0, 1

n = int(input().strip())
lines = [ int(input().strip()) for _ in range(n)]
user_stack = deque()
result = 0

for cur_height in lines : 
    # 스택에는 현재 확인하려는 키보다 큰 키만 남아 있어야 함
    while user_stack and user_stack[-1][HEIGHT] < cur_height:
        _, height_cnt = user_stack.pop()
        # 현재 확인하려는 키와 마주볼 수 있는 사람의 수를 더해줌
        result += height_cnt

    # 스택이 비어있으면 현재 키와 마주볼 수 있는 키가 없음 
    if not user_stack:
        user_stack.append((cur_height, 1))
        continue

    # 키가 같다면 
    if cur_height == user_stack[-1][HEIGHT]:
        _, height_cnt = user_stack.pop()
        result += height_cnt
        
        # 스택이 비어있지 않다면 마주 볼 수 있는 사람이 있음 
        if user_stack:
            result += 1 

        user_stack.append((cur_height, height_cnt + 1 ))
    
    # 현재 키가 스택의 키보다 작다면     
    else :
        result += 1 
        user_stack.append((cur_height,1))

print(result)