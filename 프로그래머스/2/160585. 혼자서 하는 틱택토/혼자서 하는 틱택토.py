"""
가로, 세로, 대각선
"""

def doesGameDone(board, r, c, targetstr):
    target = targetstr * 3
    
    # 가로
    if(board[r] == target):
        return True
    # 세로
    if(board[0][c] + board[1][c] + board[2][c]  == target):
        return True
    # 대각선
    if(board[0][0] + board[1][1] + board[2][2]  == target):
        return True
    # 대각선
    if(board[0][2] + board[1][1] + board[2][0]  == target):
        return True
    
    return False
    
def solution(board):
    isDone = False 
    
    cnt_X = 0
    cnt_O = 0
    
    for r in range(3):
        for c in range(3):
            cnt_X += int('X' == board[r][c])
            cnt_O += int('O' == board[r][c])
            
            isDone |= doesGameDone(board, r, c, board[r][c])
                
    answer = int(((True == isDone) and (cnt_X + 1 == cnt_O)) \
            or ((False == isDone) and (cnt_X == cnt_O))\
            or ((False == isDone) and (cnt_X + 1 == cnt_O)))
    
    return answer