def changetime (time,taken):
    taken = taken[:len(taken)-1]
    clock = int(time.split(':')[0]) * 3600
    minute = int(time.split(':')[1]) * 60
    second = time.split(':')[2]
    total_second = clock + minute + float(second)
    total_second = round(total_second,3)
    start_second = float(total_second) - float(taken) + 0.001
    start_second = round(start_second,3)
    return (start_second,total_second)

def timecheck(time,times):
    cnt = 0
    start = time
    end = time + 1
    for i in times:
        if not(start > i[1] or end <= i[0]):
            cnt = cnt + 1
    return cnt

def solution(lines):
    time = []
    for i in lines:
        sectime = i.split(' ')[1]
        taken = i.split(' ')[-1]
        time.append(changetime(sectime,taken))
    total_cnt = 0
    for i in time:
        start = timecheck(i[0],time)
        end = timecheck(i[1],time)
        if total_cnt < start:
            total_cnt = start
        if total_cnt < end:
            total_cnt = end
    return total_cnt