from bisect import bisect_left

N = map(int,input())
coord_list = list(map(int,input().split(' ')))

# 중복제거 후 정렬 
list_for_search = sorted(list(set(coord_list)))
len_of_search_list = len(list_for_search)

for item in coord_list:
    res = bisect_left(list_for_search,item,0,len_of_search_list)
    print(res,end=' ')