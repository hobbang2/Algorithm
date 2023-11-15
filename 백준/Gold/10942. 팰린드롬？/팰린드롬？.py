import sys 
input = sys.stdin.readline

N = int(input())
suggest_numbers = [0] + list(map(int,input().split(' ')))
T = int(input())
tc = [ list(map(int, input().split())) for _ in range(T)]
# dp[1][3] : index 1부터 3까지 숫자의 펠린드롬 여부
dp = [ [0] * (N + 1) for _ in range( N + 1)]

for num in range(1, N + 1):

    # 한 자리 숫자는 펠린드롬 
    dp[num][num] = 1
    
    # 두 자리 숫자의 시작과 끝이 같으면 펠린드롬
    if( (num != N)
        and ( suggest_numbers[num] == suggest_numbers[num + 1]) ):
        dp[num][num + 1] = 1 

for pel_len in range(3, N + 1):
    for start_idx in range(1, N + 1 - pel_len + 1):

        if((suggest_numbers[start_idx] == suggest_numbers[start_idx + pel_len - 1])
           and (1 == dp[start_idx + 1][start_idx + pel_len - 2])):
            dp[start_idx][start_idx + pel_len - 1] = 1
        # 시작점과 마지막 지점의 숫자를 비교 
        # 시작점 + 1 과 시작점 + 길이 -1 이 펠린드롬인지 확인 

for s, e in tc:
    print(dp[s][e])
