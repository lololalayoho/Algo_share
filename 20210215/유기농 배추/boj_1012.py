# 유기농 배추 https://www.acmicpc.net/problem/1012
import sys
sys.setrecursionlimit(2503)

def dfs(par_y, par_x):
    if par_x >= M or par_y >= N or par_x <= -1 or par_y <= -1:
        return False
    elif graph[par_y][par_x] == 1:
        graph[par_y][par_x] = 0
        dfs(par_y+1, par_x)
        dfs(par_y-1, par_x)
        dfs(par_y, par_x+1)
        dfs(par_y, par_x-1)
        return True
    else:
        return False

result = []
count = 0

T = int(input())

for _ in range(T):
    # 가로길이 M, 세로길이 N, 배추가 심어진 위치의 개수 K
    M, N, K = map(int, input().split())

    graph = [[0] * M for _ in range(N)]

    for _ in range(K):
        x, y = map(int, input().split())
        graph[y][x] = 1

    # Test Case 수 만큼 돌리기
    for k in range(T):
        for i in range(M):
            for j in range(N):
                if dfs(j, i) == True:
                    count += 1
    
    result.append(count)

    graph = [[0] * M for _ in range(N)]
    count = 0

for node in result:
    print(node)

print(sys.getrecursionlimit())