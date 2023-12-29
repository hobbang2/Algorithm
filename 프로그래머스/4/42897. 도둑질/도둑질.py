def solution(money):
    dp_first = [0] * len(money)
    dp_first[0] = dp_first[1] = money[0]
    
    for idx in range(2, len(money) - 1):
        dp_first[idx] = max(dp_first[idx - 1], money[idx] + dp_first[idx - 2])

    dp_second = [0] * len(money)
    dp_second[0] = 0
    dp_second[1] = money[1]
    
    for idx in range(2, len(money)):
        dp_second[idx] = max(dp_second[idx - 1], money[idx] + dp_second[idx - 2])


    
    answer = max(max(dp_first), max(dp_second))
    return answer