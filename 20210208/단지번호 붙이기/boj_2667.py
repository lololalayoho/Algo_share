# 단지번호 붙이기

N = int(input())

graph = []
list_num = []
count = 0

for _ in range(N):
    graph.append(list(map(int, input())))

def dfs(x, y):
    global count
    # 주어진 범위를 벗어나는 경우 종료
    if x <= -1 or y <= -1 or x >= N or y >= N:
        return False
    if graph[x][y] == 1:
        count += 1
        graph[x][y] = 0
        dfs(x-1, y)
        dfs(x+1, y)
        dfs(x, y+1)
        dfs(x, y-1)
        return True
    return False

result_group = 0

for i in range(N):
    for j in range(N):
        if dfs(i, j) == True:
            result_group += 1
            list_num.append(count)
            count = 0

list_num.sort()
print(result_group)
for i in list_num:
    print(i)
