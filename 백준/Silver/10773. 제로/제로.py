import sys
input = sys.stdin.readline
k = int(input().strip())
cur_num_list = []

for idx in range(k):
    
    cur_num = int(input())
    
    if( 0 == cur_num):
        cur_num_list.pop()
    else:
        cur_num_list.append(cur_num)
        
print(sum(cur_num_list))