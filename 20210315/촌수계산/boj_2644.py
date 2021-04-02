# 촌수계산 https://www.acmicpc.net/problem/2644
from collections import deque

queue = deque()

n = int(input())
# 찾을 사람 2명 입력
p1, p2 = map(int, input().split())
m = int(input())

visited = [False] * (n+1)

array = [[] for _ in range(n+1)]
count = [0] * (n+1)

for _ in range(m):
    # 부모 자식 관계 입력
    p, d = map(int, input().split())
    array[p].append(d)
    array[d].append(p)

queue.append(p1)

while queue:
    temp = queue.popleft()
    visited[temp] = True

    for i in array[temp]:
        if not visited[i]:
            queue.append(i)

    for i in array[temp]:
        in not visited[i]:
            count[i] = count[temp]+1
        else:
            continue

if count[p2] != 0:
    print(count[p2])
else:
    print(-1)