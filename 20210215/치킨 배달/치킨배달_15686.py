from itertools import combinations

N, M = map(int, input().split())

graph = list()
distance_list = list()
result_list = list()
result = list()
min_val = 0
temp_list = list()

for _ in range(N):
    graph.append(list(map(int, input().split())))

# 치킨집 좌표 구하기
chk_list = list()
for i in range(N):
    for j in range(N):
        if graph[i][j] == 2:
            chk_list.append((i, j))

# 치킨집 좌표 M개 조합 구하기
cPositions = list(combinations(chk_list, M))

for cPosition in cPositions:
    result.clear()
    for i in range(N):
        for j in range(N):
            if graph[i][j] == 1:
                for c in cPosition:
                    distance = abs(i - c[0]) + abs(j - c[1])
                    distance_list.append(distance)
                min_val = min(distance_list)
                result.append(min_val)
                distance_list.clear()
    temp_list = result.copy()
    result_list.append(temp_list)
    # print(result_list)

sum_list = list()
for result in result_list:
    sum_list.append(sum(result))

answer = min(sum_list)
print(answer)