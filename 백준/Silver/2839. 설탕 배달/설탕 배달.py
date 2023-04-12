N = int(input())

max_five = N // 5
remain = N % 5 

def get_cnt(u_max_five : int) -> int:
    
    for idx in range(max_five,-1,-1):
        remain = N - idx * 5 
    
        if( remain % 3 == 0 ):
            return ( idx + (remain // 3 ))
        
    return -1

print(get_cnt(max_five))