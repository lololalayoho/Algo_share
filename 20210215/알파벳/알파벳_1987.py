# 알파벳 https://www.acmicpc.net/problem/1987
import sys
from string import ascii_uppercase
sys.setrecursionlimit(10000)

R, C = map(int, input().split())

graph = []
rest = list(ascii_uppercase)
count = 0
max_count = 0

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for _ in range(R):
    read = sys.stdin.readline().rstrip()
    graph.append(read)

def Search(par_x, par_y):
    global count
    global max_count

    count += 1
    if count > max_count:
        max_count = count

    for i in range(4):
        new_x = par_x + dx[i]
        new_y = par_y + dy[i]

        if new_x <= -1 or new_y <= -1 or new_x >= R or new_y >= C:
            continue
        if graph[new_x][new_y] not in rest:
            continue

        temp_idx = rest.index(graph[new_x][new_y])
        del rest[temp_idx]

        Search(new_x, new_y)
        rest.append(graph[new_x][new_y])

    count -= 1

first = graph[0][0]
rest.remove(first)
Search(0, 0)
print(max_count)