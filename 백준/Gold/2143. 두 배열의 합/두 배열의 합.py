import bisect
# 숫자는 -10억 이상 10억 이하
# 각 1000개의 원소를 가진 집합 2개
# 두 집합의 부분집합에 속하는 원소들의 합이 T 를 만족하는 갯수 

def getSumListOfSet( target_set:list ):
    target_set_n = len(target_set)
    res_list = []

    for outter_idx in range(0,target_set_n):
        cur_sum = target_set[outter_idx]
        res_list.append(cur_sum)
        for inner_idx in range(outter_idx+1,target_set_n):
            cur_sum += target_set[inner_idx]
            res_list.append(cur_sum)
    return res_list 

T = int(input())
A_n = int(input())
A_numbers = list(map(int,input().split()))
B_n = int(input())
B_numbers = list(map(int,input().split()))

A_sum = []
B_sum = []

answer = 0 
# A_sum 
A_sum = getSumListOfSet(A_numbers)

# B_sum
B_sum = getSumListOfSet(B_numbers)

A_sum.sort()
B_sum.sort()

A_sum_n = len(A_sum)
for idx in range(A_sum_n):
    lower = bisect.bisect_left(B_sum,T-A_sum[idx])
    upper = bisect.bisect_right(B_sum,T-A_sum[idx])
    answer += upper - lower 

print(answer)
