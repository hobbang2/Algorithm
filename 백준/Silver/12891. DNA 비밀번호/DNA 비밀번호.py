from collections import defaultdict
from collections import Counter

# 최소 개수를 충족하는지 확인 
def is_satisfy(cur_counter:dict, necessary_dict:dict, target_alpha:list):
    
    for t in target_alpha:
        if (cur_counter[t] < necessary_dict[t]):
            return False 
        
    return True 

S, P = map(int,input().split(' '))
dna_str = input()

need_alpha = ['A','C','G','T']
need_cnt = list(map(int, input().split(' ')))
cur_alpha_cnt = Counter(dna_str[:P])
result = 0 

# 각 알파벳마다 필요한 개수 저장
need_dict = {}
for a, c in zip(need_alpha, need_cnt):
    need_dict[a] = c

# 최초 문자열 조건 만족 여부 확인 
result += int(is_satisfy(cur_alpha_cnt, need_dict, need_alpha))

# 뒷 문자를 하나씩 확인하면서 조건 충족 여부 확인
for idx in range(P, S):
    ex_alpha = dna_str[idx - P]
    next_alpha = dna_str[idx]
    cur_alpha_cnt[ex_alpha] -= 1
    cur_alpha_cnt[next_alpha] += 1

    result += int(is_satisfy(cur_alpha_cnt, need_dict, need_alpha))
        
print(result)