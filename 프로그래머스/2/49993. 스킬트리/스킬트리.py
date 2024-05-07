def solution(skill, skill_trees):
    answer = 0
    skillsize = len(skill)
    
    for treeidx, st in enumerate(skill_trees):
        checkarr = [idx for idx in range(skillsize )] 
        visitarr = [False for idx in range(skillsize )] 

        for skillidx, s in enumerate(skill):
            for treeitemidx, stitem in enumerate(st):

                if( s == stitem):
                    visitarr[skillidx] = True
                    checkarr[skillidx] = treeitemidx

        addvalue = 1  

        for idx in range(0, skillsize - 1):
            # 건너뛰고 학습하는 트리는 안됨
            if((False == visitarr[idx] and True == visitarr[idx + 1])):           
                
                addvalue = 0 
                break
            # 순서가 꼬인 트리는 안됨
            if((True == visitarr[idx] and True == visitarr[idx + 1])):
                
                if(checkarr[idx] > checkarr[idx + 1]):
                    addvalue = 0 
                    break
            
        answer += addvalue 
    return answer