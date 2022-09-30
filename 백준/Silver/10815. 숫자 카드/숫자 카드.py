from bisect import bisect

# 1부터 50만 , 상근이가 가지고 있는 카드 개수
N = int(input())
my_card_list = sorted(list(map(int,input().split())))
M = int(input())
check_list = list(map(int,input().split()))

for check_item in check_list:
    finded_idx = bisect(my_card_list, check_item) 
    cur_ans = int(False)

    if( check_item == my_card_list[finded_idx -1] ):
        cur_ans = int(True)
    print( cur_ans, end=" ")