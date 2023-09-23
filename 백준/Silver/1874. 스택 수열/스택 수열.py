"""
1부터 n까지의 수를 스택에 넣었다 뽑아 늘어놓기 
"""
import sys 
input = sys.stdin.readline
n = int(input().strip())
sequence = [int(input().strip()) for _ in range(n)]

my_stack = [1]
answer = ['+']
cur_num = 2
cnt = 0

for s in sequence:
    # 현재 스택에 s랑 같은 숫자가 생길 때까지 
    if not my_stack and (cur_num <=n):
        my_stack.append(cur_num)
        answer.append('+')
        cur_num += 1 
        
    while my_stack:
        top_value = my_stack[-1]
        
        if(top_value == s):
            my_stack.pop()
            answer.append('-')
            cnt += 1 
            break
        elif(top_value > s):
            my_stack.pop()
            
        elif(cur_num <= n):
            my_stack.append(cur_num)
            answer.append('+')
            cur_num += 1
        else:
            break
        
if( cnt == n):
    print('\n'.join(answer))
else:
    print("NO")
    