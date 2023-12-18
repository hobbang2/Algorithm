def solution(distance, rocks, n):
    
    answer = 0
    start, end = 0, distance
    rocks.append(distance)
    rocks.sort()
    
    while start <= end:
        mid = (start + end) // 2
        deleted_num = 0
        ex_stone = 0
        
        for rock in rocks:
            if rock - ex_stone < mid:
                deleted_num += 1
            else:
                ex_stone = rock
                
            if deleted_num > n :
                break
                
        if deleted_num > n :
            end = mid - 1
        else:
            answer = mid
            start = mid + 1
    
    return answer