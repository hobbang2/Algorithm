answer = -1
visited = [[0] * 501 for _ in range(501)]

def dfs(r:int , c:int, max_height:int, result:int, triangle:list):
    
    global answer

    if(r >= max_height - 1):
        answer = max(answer, result)
        return
    
    if(r < max_height - 1):
        if(False == visited[r + 1][c]):
            visited[r + 1][c] = True 
            dfs(r + 1, c, max_height, result + triangle[r + 1][c],triangle)
    
        if( c != r):
            if(False == visited[r + 1][c + 1]):
                visited[r + 1][c + 1] = True
                dfs(r + 1, c + 1, max_height, result + triangle[r + 1][c + 1],triangle)

def solution(triangle):
    dfs(0, 0, len(triangle), triangle[0][0], triangle)
    return answer