N, C = map(int, input().split()) # 마을 개수와 용량
M = int(input()) # 보내는 박스 정보
send_info = [ list(map(int,input( ).split(' '))) for m in range(M)]
send_info.sort(key=lambda x :  x[1])
send_num_info = [0 for _ in range(N + 1)]
max_box_num = 0
result = 0

for s, e, c in send_info:
    # s부터 e 전 까지 트럭에 담긴 택배 수 중 가장 큰 것
    max_box_num = max(send_num_info[s: e])
    # 현재 시점에서 담을 수 있는 택배 수 
    available_capacity = C - max_box_num
    # 현재 시점에서 담을 수 있는 택배 수가 배송할 택배 수보다 작으면     
    if(available_capacity < c):
        cur_capacity = available_capacity
    # 모두 담을 수 있으면 
    else:
        cur_capacity = c
    # s부터 e 전까지 트럭에 담긴 택배수 갱신하기
    for truck_no in range(s, e):
        send_num_info[truck_no] += cur_capacity
    
    result += cur_capacity

print(result)
    

    