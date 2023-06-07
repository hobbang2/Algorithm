"""
( 와 )만으로 구성되어 있는 문자열 
올바른 괄호 문자열인지 판단하자 
VPS이면 YES 아니면 NO    
"""

T = int(input())

for tc in range(T):
    
    bracket_str = list(input())
    cur_stack = []
    
    for bracket in bracket_str :
        result = 'YES'
        
        if( '(' == bracket):
            cur_stack.append(bracket)
            
        elif( 0 == len(cur_stack)):
            result = 'NO'
            break

        elif(')'== bracket):
            cur_stack.pop()
        
    if( 0 < len(cur_stack)):
        result = 'NO'
    
    print(result) 
                        
    