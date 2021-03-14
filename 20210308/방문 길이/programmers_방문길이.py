#https://programmers.co.kr/learn/courses/30/lessons/49994?language=python3

from collections import deque

array= deque()
graph = [[0 for i in range(21)] for j in range(21)]
pos = [10, 10]

# 상 하 좌 우
dx1 = [-1, 1, 0, 0]
dy1 = [0, 0, -1, 1]

dx2 = [-2, 2, 0, 0]
dy2 = [0, 0, -2, 2]

def solution(dirs):
    count = 0

    for i in dirs:
        array.append(i)
        
    while array:
        temp = array.popleft()
        
        if temp == "U":
            temp_x1 = pos[0] + dx1[0]
            temp_y1 = pos[1] + dy1[0]
            temp_x2 = pos[0] + dx2[0]
            temp_y2 = pos[1] + dy2[0]
            
            if temp_x2 < 0 or temp_x2 > 20 or temp_y2 < 0 or temp_y2 > 20:
                continue
            
            else:
                pos[0] = temp_x2
                pos[1] = temp_y2
                
                if graph[temp_x1][temp_y1] == 0 :
                    graph[temp_x1][temp_y1] = 2
            
        elif temp == "D":
            temp_x1 = pos[0] + dx1[1]
            temp_y1 = pos[1] + dy1[1]
            temp_x2 = pos[0] + dx2[1]
            temp_y2 = pos[1] + dy2[1]
    
            if temp_x2 < 0 or temp_x2 > 20 or temp_y2 < 0 or temp_y2 > 20:
                continue
            
            else:
                pos[0] = temp_x2
                pos[1] = temp_y2
                if graph[temp_x1][temp_y1] == 0:
                    graph[temp_x1][temp_y1] = 2
                
        elif temp == "L":
            temp_x1 = pos[0] + dx1[2]
            temp_y1 = pos[1] + dy1[2]
            temp_x2 = pos[0] + dx2[2]
            temp_y2 = pos[1] + dy2[2]
            
            if temp_x2 < 0 or temp_x2 > 20 or temp_y2 < 0 or temp_y2 > 20:
                continue
            
            else:
                pos[0] = temp_x2
                pos[1] = temp_y2
                if graph[temp_x1][temp_y1] == 0:
                    graph[temp_x1][temp_y1] = 2
                
        elif temp == "R":
            temp_x1 = pos[0] + dx1[3]
            temp_y1 = pos[1] + dy1[3]
            temp_x2 = pos[0] + dx2[3]
            temp_y2 = pos[1] + dy2[3]
            
            if temp_x2 < 0 or temp_x2 > 20 or temp_y2 < 0 or temp_y2 > 20:
                continue
            else:
                pos[0] = temp_x2
                pos[1] = temp_y2
                if graph[temp_x1][temp_y1] == 0:
                    graph[temp_x1][temp_y1] = 2
            
    for i in range(21):
        for j in range(21):
            if graph[i][j] == 2:
                count += 1
                
    return count