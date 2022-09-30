# 1부터 50만 , 상근이가 가지고 있는 카드 개수
N = int(input())
my_card_list = sorted(list(map(int,input().split())))
M = int(input())
check_list = list(map(int,input().split()))

def user_binary_search(low:int, upper:int, target:int, my_cards:list):
    while( low <= upper):
        mid = (low + upper)//2
        cur_num = my_cards[mid]

        if( cur_num > target ):
            upper = mid - 1 
        elif( cur_num < target):
            low = mid + 1
        else:
            return int(True)
    return int(False)

for check_item in check_list:
    print( user_binary_search(0,N - 1,check_item,my_card_list),end=" ")