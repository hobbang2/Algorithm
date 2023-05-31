import sys 
input = sys.stdin.readline

DICE_NUM = int(input().rstrip())
dice_list = [ list(map(int,input().rstrip().split(' '))) for _ in range(DICE_NUM)]
dice_dict = {
    0:5,
    1:3,
    2:4,
    3:1,
    4:2,
    5:0
}

result = 0 

for idx in range(6):
    
    cur_top_num = dice_list[0][idx]
    side_list = [ dice_list[0][_] for _ in range(6) if _ != idx and _ != dice_dict[idx]]
    cur_result = max(side_list)

    for next_dice_idx in range(1, DICE_NUM):
        
        below_idx = dice_list[next_dice_idx].index(cur_top_num)
        top_idx = dice_dict[below_idx]
        cur_top_num = dice_list[next_dice_idx][top_idx]
        side_list = [ dice_list[next_dice_idx][_] for _ in range(6) if _ != top_idx and _ != below_idx]
        cur_result += max(side_list)
    
    result = max(result, cur_result)

print(result)


