"""
( 와 )만으로 구성되어 있는 문자열 
올바른 괄호 문자열인지 판단하자 
VPS이면 YES 아니면 NO    
"""

T = int(input())

for tc in range(T):
    
    bracket_str = list(input())
    cnt = 0 
    
    for bracket in bracket_str :
        result = 'YES'
        
        if( cnt < 0 ):
            result = 'NO'
            break
            
        mul_val = 1 if '(' == bracket  else -1
        cnt += 1 * mul_val
        
    if( 0 != cnt):
        result = 'NO'
    
    print(result) 
                        
    