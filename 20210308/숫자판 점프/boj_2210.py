# 숫자판 점프_2210 https://www.acmicpc.net/problem/2210
import sys
sys.setrecursionlimit(10000)


graph = list()

visitied = list()
sub_visited = list()
lists = list()
temp_list = list()

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for _ in range(5):
    graph.append(list(map(int, input().split())))

def dfs(x, y):
    temp_list.append(graph[x][y])
    sub_visited.append((x, y))

    if len(temp_list) == 6:
        if temp_list in lists or sub_visited in visitied:
            return
        elif temp_list not in lists and sub_visited not in visitied:
            lists.append(temp_list.copy())
            visitied.append(sub_visited.copy())
            return

    for i in range(4):
        new_x = x + dx[i]
        new_y = y + dy[i]

        if new_x < 0 or new_x > 4 or new_y < 0 or new_y > 4:
            continue
        
        dfs(new_x, new_y)
        sub_visited.pop()
        temp_list.pop()


for i in range(5):
    for j in range(5):
        dfs(i, j)
        temp_list.clear()
        sub_visited.clear()

print(len(lists))