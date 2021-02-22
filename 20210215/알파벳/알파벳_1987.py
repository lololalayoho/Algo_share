# 알파벳 https://www.acmicpc.net/problem/1987
import sys
sys.setrecursionlimit(10000)

R, C = map(int, input().split())

graph = []
visited = list()
result = list()
count = 0

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for _ in range(R):
    read = sys.stdin.readline().rstrip()
    graph.append(read)

def Search(par_x, par_y, count):
    if (par_x <= -1 or par_y <= -1 or par_x >= R or par_y >= C) or (graph[par_x][par_y] in visited):
        return

    count += 1
    temp = graph[par_x][par_y]
    visited.append(temp)
    result.append(count)

    for i in range(4):
        new_x = par_x + dx[i]
        new_y = par_y + dy[i]

        Search(new_x, new_y)
    
    del visited[-1]

Search(0, 0, count)
print(max(result))