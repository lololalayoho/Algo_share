# https://www.acmicpc.net/problem/7576

from collections import deque

# M은 가로 수, N은 세로 수
M, N = map(int, input().split())

queue = deque()
graph = list()
count = 0


dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for _ in range(N):
    graph.append(list(map(int, input().split())))

def getMax(graph):
    global count
    for i in range(N):
        for j in range(M):
            if graph[i][j] > count:
                count = graph[i][j]

def checkGraph(graph):
    for i in range(N):
        for j in range(M):
            if graph[i][j] != 0:
                continue
            elif graph[i][j] == 0:
                return False
    return True
            
def checkTomato(graph):
    for i in range(N):
        for j in range(M):
            if graph[i][j] == 1:
                queue.append((i, j))

def bfs(x, y):
    for i in range(4):
        new_x = temp[0] + dx[i]
        new_y = temp[1] + dy[i]

        if new_x < 0 or new_x >= N or new_y < 0 or new_y >= M:
            continue

        if graph[new_x][new_y] == -1:
            continue

        if graph[new_x][new_y] == 0:
            queue.append((new_x, new_y))
            graph[new_x][new_y] = graph[temp[0]][temp[1]] + 1
        
        else:
            continue
            
checkTomato(graph)

while queue:
    temp = queue.popleft()
    bfs(temp[0], temp[1])

result = checkGraph(graph)
if result == False:
    print(-1)
else:
    getMax(graph)
    print(count-1)