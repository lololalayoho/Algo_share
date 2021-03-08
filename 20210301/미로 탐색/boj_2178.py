# boj_2178 미로 탐색 https://www.acmicpc.net/problem/2178
import sys
from collections import deque

N, M = map(int, input().split())

graph = []
queue = deque()

for i in range(N):
    graph.append(list(map(int, input())))

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(start_x, start_y):
    queue.append([start_x, start_y])
    while queue:
        temp = queue.popleft()
        old_x = temp[0]
        old_y = temp[1]
        for i in range(4):
            new_x = old_x + dx[i]
            new_y = old_y + dy[i]

            if new_x >= N or new_x < 0 or new_y >= M or new_y < 0:
                continue

            if graph[new_x][new_y] == 1:
                queue.append([new_x, new_y])
                graph[new_x][new_y] = graph[old_x][old_y] + 1

bfs(0, 0)
print(graph[N-1][M-1])

    