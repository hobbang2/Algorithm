"""
레이저 절단 
쇠막대기는 자신보다 긴 쇠막대기 위에만 놓일 수 있음 
- 쇠막대기를 다른 쇠막대기 위에 놓는 경우 완전히 포함되도록 놓되 끝점은 겹치지 않는다.
- 각 쇠막대기를 자르는 레이저는 적어도 하나 존재
- 레이저는 어떤 쇠막대기의 양 끝점과도 겹치지 않음 

잘려진 쇠막대기 조각의 총 수
"""
sequence = list(input())

cur_stick_num = 0
ex = ''
res = 0

for bracket in sequence:

    # 레이저    
    if( ex == '(' and bracket == ')'):
        cur_stick_num -= 1 # 레이저 카운트 된거 빼줌
        res += cur_stick_num
    
    elif(bracket == '('):
        cur_stick_num += 1
        
    else:
        res += 1
        cur_stick_num -= 1 
        
    ex = bracket
    
print(res)