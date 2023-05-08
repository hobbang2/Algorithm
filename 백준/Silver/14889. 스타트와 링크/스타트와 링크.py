N = int(input())
ability = [ list(map(int,input().split(' '))) for _ in range(N)]
res = 200000

# 팀을 나누고 for 문을 돌면서 ability를 구하자
def backtracking(ability:list, idx : int,  limit: int, cnt:int, start_str:str)->None:
    global res 
    
    if(limit == cnt):
        # 팀이 다 나누어짐 
        if(start_str[0] == '|'):
            start_str = start_str[1:]
        start_list = list(map(int,start_str.split('|')))
        link_list = [ elem  for elem in range(limit * 2) if elem not in start_list]
        start_score = 0
        link_score = 0
        
        for fidx in range(0, limit ):
            for sidx in range(fidx + 1, limit ):
                s, ss = start_list[fidx], start_list[sidx]
                l, ll = link_list[fidx], link_list[sidx]
                start_score += ability[s][ss] + ability[ss][s]
                link_score += ability[l][ll] + ability[ll][l]
                
        cur_res = abs(start_score - link_score) 
        res = res if res < cur_res else cur_res

        return 
        
    for cur_idx in range(idx, limit * 2):
        
        if(str(cur_idx) in (start_str)):
            continue
        backtracking(ability, cur_idx + 1, limit, cnt + 1, start_str + '|' + str(cur_idx))

backtracking(ability, 0, N//2, 0, "")  

print(res)