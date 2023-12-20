from collections import defaultdict 

def solution(gems):
    answer = [100001, 100001]
    sequence_len = len(gems) + 10
    
    # end_point를 늘리면서 보석을 담음
    required_kind_cnt = len(set(gems))
    getting_gem_dict = defaultdict(int)
    
    cur_cnt = 0 
    gems_len = len(gems)
    end_point = 0 
    
    for start_point in range(gems_len):
#         cur_gem = gems[start_point]
        
#         if( 0 == getting_gem_dict[cur_gem]):
#             cur_cnt += 1
            
#         getting_gem_dict[cur_gem] += 1
        
        while cur_cnt < required_kind_cnt and end_point < gems_len:
            cur_gem = gems[end_point]
        
            if( 0 == getting_gem_dict[cur_gem]):
                cur_cnt += 1
            
            getting_gem_dict[cur_gem] += 1
            
            end_point += 1
        
        cur_sequence_len = end_point - start_point
        
        if((cur_cnt == required_kind_cnt)):
            if(sequence_len > cur_sequence_len):
                sequence_len = cur_sequence_len
                answer = [start_point, end_point]
            elif(answer[0] > start_point):
                answer = [start_point, end_point]
            else:
                pass
        cur_gem = gems[start_point]
        
        if( 1 == getting_gem_dict[cur_gem]):
            cur_cnt -= 1        
        getting_gem_dict[cur_gem] -= 1 

    return [answer[0] + 1, answer[1] ]