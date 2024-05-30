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
    is_done_X = False 
    is_done_O = False 
    answer = 0 
    cnt_X = 0
    cnt_O = 0
    
    for r in range(3):
        for c in range(3):
            if('X' == board[r][c]):
                cnt_X += 1
                is_done_X |= doesGameDone(board, r, c, board[r][c])
            elif('O' == board[r][c]):
                cnt_O += 1
                is_done_O |= doesGameDone(board, r, c, board[r][c])
                
    if(is_done_X & is_done_O):
        answer = 0 
    else:

        answer = int(
                ((True == is_done_O) and (cnt_X + 1 == cnt_O)) \
                or ((True == is_done_X) and (cnt_X == cnt_O ))\
                or ((False == is_done_O) and (False == is_done_X) and (cnt_X == cnt_O))
                or ((False == is_done_O) and (False == is_done_X) and (cnt_X + 1 == cnt_O))
                )
    return answer