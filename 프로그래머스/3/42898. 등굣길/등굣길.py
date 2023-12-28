USER_MOD = 1000000007
def solution(m, n, puddles):
    answer = 0
    dp = [ [0] * (m + 2) for _ in range(n + 2)]
    dp[1][1] = 1
    for c, r in puddles:
        dp[r][c] = 0
    
    for r in range(1, n + 1):
        for c in range(1, m + 1):
            if([r,c] == [1, 1]):
                continue
            
            if([c, r]  in puddles):
                continue
                
            dp[r][c] = (dp[r - 1][c] + dp[r][c - 1]) % USER_MOD
        
    # print(dp[n - 1][m - 1])

    return dp[n][m]
# print(solution(2, 2, []), 2)
# print(solution(3, 3, []), 6)
# print(solution(3, 3, [[2, 2]]), 2)
# print(solution(3, 3, [[2, 3]]), 3)
# print(solution(3, 3, [[1, 3]]), 5)
# print(solution(3, 3, [[1, 3], [3, 1]]), 4)
# print(solution(3, 3, [[1, 3], [3, 1], [2, 3]]), 2)
# print(solution(3, 3, [[1, 3], [3, 1], [2, 3], [2, 1]]), 1)
# print(solution(7, 4, [[2, 1], [2, 2], [2, 3], [4, 2], [4, 3], [4, 4], [6, 2], [6, 3]]), 0) # 이 값이 잘 나오면 테스트1, 테스트9 통과, 위로 가면 안됨
# print(solution(4, 4, [[3, 2], [2, 4]]), 7)
# print(solution(100, 100, []), 690285631)
