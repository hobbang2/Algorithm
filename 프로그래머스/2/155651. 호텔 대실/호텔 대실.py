def solution(book_time):
    
    answer = 0
    roomlist = []
    book_time.sort()
    
    for item in book_time:
        entertime = int(item[0][:2]) * 60 + int(item[0][3:])
        exittime  = int(item[1][:2]) * 60 + int(item[1][3:]) + 10
        if len(roomlist) == 0:
            roomlist.append([entertime, exittime])
            
        else:
            for roomidx, room in enumerate(roomlist):
                if(room[1] <= entertime):
                    roomlist[roomidx] = [entertime, exittime]
                    break
            else:
                roomlist.append([entertime, exittime])
                
    return len(roomlist)