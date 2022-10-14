N = int( input() )

pipe_list = []

for pipe_idx in range(N):
    cur_pipe = int(input())
    pipe_list.append(cur_pipe)

pipe_list.sort(reverse=True)

max_weight = 0 
ex_max_weight = max_weight

sum_weight = 0 
min_weight = 10002

cnt = 0 

# min weight 을 k 개 
for cur_pipe in pipe_list :
    cnt += 1
    
    min_weight = min( min_weight, cur_pipe)
    max_weight = max( max_weight , min_weight * cnt )
    

print(max_weight)
