from bisect import bisect

# 집합 A 에는 속하고, B 에는 속하지 않는 모든 원소

n_A , n_B = list( map ( int, input().split()))
user_set_A = sorted(list( map ( int, input().split())))
user_set_B = sorted(list( map ( int, input().split())))

not_in_B_elem = []

for item in user_set_A : 
    check_idx = bisect(user_set_B, item)
    check_item = user_set_B[check_idx - 1 ]
    
    if( check_item != item ):
        not_in_B_elem.append(item)

print( len(not_in_B_elem) )
for res_item in not_in_B_elem:
    print( res_item , end = ' ')

