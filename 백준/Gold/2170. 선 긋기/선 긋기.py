import sys 
input = sys.stdin.readline

N = int(input())

lines = [ tuple(map(int,input().split(' '))) for n in range(N)]
lines.sort()

result_x, result_y = lines[0] 
result = 0

for x, y in lines[1:]:

    # 현재 x, y가 이전 x, y에 걸치지 않는 경우
    if((x > result_y)):
        result += result_y - result_x
        result_x = x ; result_y = y
    # 현재 x, y가 이전 x, y에 걸친 경우 
    elif((x <= result_y )):
        result_y = max(y, result_y)

    else:
        pass         

result += result_y - result_x
print(result)
