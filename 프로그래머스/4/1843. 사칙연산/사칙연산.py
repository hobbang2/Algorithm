def solution(arr):
    """
    dp에 부분식의 값을 저장하면서 연산 
    1 - 3 = -2
    1 - 5 = -3
    1 + 3 = 4
    1 + 5 = 6
    => 부호가 '-'일 때는 오른쪽 항의 값이 작은 것 
    => 부호가 '+'일 때는 오른쪽 항의 값이 큰 것
    """
    # STEP1. 숫자 변환하기
    arr_size = len(arr)

    # STEP2. DP 배열 선언 (start to end 값 저장)
    dp_max = [[0 for _ in range(arr_size)] for _ in range(arr_size)]
    dp_min = [[0 for _ in range(arr_size)]  for _ in range(arr_size)]
    
    for idx in range(0, arr_size, 2):
        arr[idx] = int(arr[idx])
        dp_max[idx][idx] = arr[idx]
        dp_min[idx][idx] = arr[idx]
    
    for expression_len in range(3, arr_size + 1, 2):
        for left_idx in range(0, arr_size, 2):
            max_candi = []
            min_candi = []
            right_idx = expression_len + left_idx - 1
            
            if(right_idx >= arr_size):
                break
            
            for op_idx in range(left_idx + 1, right_idx, 2):
                if('+' == arr[op_idx]):
                    max_candi.append(dp_max[left_idx][op_idx - 1] + dp_max[op_idx + 1][right_idx] )
                    min_candi.append(dp_min[left_idx][op_idx - 1] + dp_min[op_idx + 1][right_idx] )
                
                elif('-' == arr[op_idx]):
                    max_candi.append(dp_max[left_idx][op_idx - 1] - dp_min[op_idx + 1][right_idx] )
                    min_candi.append(dp_min[left_idx][op_idx - 1] - dp_max[op_idx + 1][right_idx] )

                else:
                    # nothing todo 
                    pass

            dp_max[left_idx][right_idx] = max(max_candi)
            dp_min[left_idx][right_idx] = min(min_candi)

    return dp_max[0][-1]

