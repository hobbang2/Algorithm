X = int(input()) # 총금액
N = int(input()) # 물건 종류 수

result = "No"
check = 0 

for idx in range(N):
    
    price, cnt = map(int, input().split(' '))
    check += price * cnt
    
result = "Yes" if (check == X) else "No"

print(result)