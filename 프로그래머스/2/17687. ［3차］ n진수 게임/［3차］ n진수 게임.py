num_to_str_dict = "0123456789ABCDEF"

def get_n_jinsu(n_jinsu:int, target:int):
    
    global num_to_str_dict
    
    if( 0 <= target < n_jinsu):
        return num_to_str_dict[target]
    
    return get_n_jinsu(n_jinsu, target // n_jinsu) + num_to_str_dict[target % n_jinsu]

def solution(n, t, m, p):
    answer = ''
    max_str_idx = ( t * m ) + m
    str_info = ""
    target_num = 0
    
    while(True):
        if(len(str_info) > max_str_idx):
            break
        str_info += get_n_jinsu(n, target_num)
        target_num += 1
    
    l = [s for idx, s in enumerate(str_info, start = 1) if ( (p % m) == (idx % m))][:t]
    
    return "".join(l)