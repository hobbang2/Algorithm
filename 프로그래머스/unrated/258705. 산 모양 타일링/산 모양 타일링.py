MOD = 10007


def solution(n, tops):
    right_dir_cover = [0 for _ in range(n + 1)]
    left_dir_cover  = [0 for _ in range(n + 1)]
    
    right_dir_cover[0] = 0
    left_dir_cover[0]  = 1
    
    for idx, t in enumerate(tops, start = 1):
        
        if( 1 == t):
            left_dir_cover[idx] = ( 2 * right_dir_cover[idx - 1] +\
                                   3 * left_dir_cover[idx - 1] ) % MOD
            
        else:
            left_dir_cover[idx] = ( right_dir_cover[idx - 1] +\
                                   2 * left_dir_cover[idx - 1] ) % MOD
            
        right_dir_cover[idx] = (right_dir_cover[idx - 1] + left_dir_cover[idx - 1]) % MOD
    
    answer = (left_dir_cover[n] + right_dir_cover[n]) % MOD
    return answer