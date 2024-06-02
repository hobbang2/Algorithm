N = int(input())
score_list = list(map(int,input().split()))
M = max(score_list)
refine_score_list = [ (s/M)*100 for s in score_list]
print(sum(refine_score_list)/N)