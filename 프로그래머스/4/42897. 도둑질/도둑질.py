def solution(money):
    
    money = [0] + money
    dp_first = [0] * len(money) 
    dp_first[1] = dp_first[2] = money[1]
    
    # 1번 집 부터 훔쳤으므로, 마지막 집은 방문할 수 없음
    for idx in range(3, len(money) - 1):
        dp_first[idx] = max(dp_first[idx - 1], money[idx] + dp_first[idx - 2])

    dp_second = [0] * len(money)
    dp_second[1] = 0 #  1번 집의 금화를 훔치지 않음 
    dp_second[2] = money[2]
    
    for idx in range(2, len(money)):
        dp_second[idx] = max(dp_second[idx - 1], money[idx] + dp_second[idx - 2])
    
    answer = max(max(dp_first), max(dp_second))
    return answer