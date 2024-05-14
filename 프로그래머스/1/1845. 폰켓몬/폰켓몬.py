# 가장 많은 종류의 포켓몬을 선택

def solution(nums):
    answer = 0
    
    poketmons = set(nums)
    max_num_poketmon = len(nums) // 2
    answer = min(max_num_poketmon, len(poketmons))
    
    return answer