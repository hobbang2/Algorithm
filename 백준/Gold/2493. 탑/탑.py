"""
탑들의 개수 N과 탑들의 높이가 주어질 때 
각 탑에서 발사한 레이저 신호를 어느 탑에서 수신하는지 알아내는 프로그램 작성

N <= 50만
높이 <= 1억
수신하는 탑 없으면 0 출력
"""
import sys
input = sys.stdin.readline

N = int(input().rstrip())
top_height = list(map(int, input().rstrip().split(' ')))
res = [ 0 for _ in range(N)]

top_stack = []

for idx, h in enumerate(top_height):
    
    if( 0 == len(top_stack)):
        top_stack.append([h,idx+1])
        res[idx] = 0
    else :
        while( (0 < len(top_stack)) and (top_stack[-1][0] < h)):
            top_stack.pop()

        res[idx] = top_stack[-1][1] if 0 < len(top_stack) else 0
        top_stack.append([h, idx + 1])

print(*res)