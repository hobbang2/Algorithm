def calculate(collect_a, collect_b):
    
    result = set()
    for item_a in collect_a:
        for item_b in collect_b:
            result.add(item_a + item_b)
            result.add(item_a - item_b)
            result.add(item_a * item_b)
            if(item_b != 0):
                result.add(item_a // item_b)
    return result
            
def solution(N, number):
    answer = -1
    
    if(N == number):
        return 1

    dp = {}
    dp[1] = {N}
    
    for t in range(2, 9):
        #  N을 t번 이어 붙인 숫자를 미리 추가해줌 
        tmp_set = {int(str(N) * t)}
        for i in range(1, t):
            cur_result_set = calculate(dp[i], dp[t - i])
            tmp_set.update(cur_result_set)
        dp[t] = tmp_set
        
        if(number in dp[t]):
            answer = t
            break
        
    return answer