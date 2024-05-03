from collections import deque

def solution(ingredient):
    target_ingredient = [1,2,3,1]
    prepare_hamburger = deque([])
    tmp_hamburger = deque([])
    target_idx = 0
    answer = 0
    
    for item in ingredient:
        
        if( (1 == item) and ( 3 <= len(prepare_hamburger))):
            flag = False
            check_item = []
            check_item.append(item)
            check_item.append(prepare_hamburger.pop())
            check_item.append(prepare_hamburger.pop())
            check_item.append(prepare_hamburger.pop())
            if(check_item[0] == 1 and check_item[1] == 3 and check_item[2] == 2 and check_item[3] == 1):
                answer += 1
            else:
                for c in check_item[::-1]:
                    prepare_hamburger.append(c)
                        
        else:
            prepare_hamburger.append(item)
        
    return answer