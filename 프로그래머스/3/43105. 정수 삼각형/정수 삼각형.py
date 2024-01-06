from collections import defaultdict

answer = -1


def dfs(point, triangle, max_height, result):
    global answer
    r, c = point
    
    if( (r + 1) == max_height ):
        answer = max(answer, result)
        return 
    
    dfs([r + 1, c], triangle, max_height, result + triangle[r + 1][c])
    dfs([r + 1, c + 1], triangle, max_height, result + triangle[r + 1][c + 1])

    return


def solution(triangle):
    dp = defaultdict(int)
    max_height = len(triangle)
    dp[(0,0)] = triangle[0][0]
    
    for h in range(1, max_height):
        for item in range(h + 1):
            dp[(h, item)] = triangle[h][item] + max(dp[(h - 1, item - 1)], dp[(h - 1, item)])
    
    return max(dp.values())
    