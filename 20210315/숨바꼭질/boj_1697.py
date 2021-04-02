# 수빈이는 N 동생은 K
# 수빈이가 동생을 찾는다
from collections import deque
import math

queue = deque()

N, K = map(int, input().split())

array = [0] * 100001
visited = [False] * 100001

# 수빈이의 자리를 큐에 삽입
queue.append(N)
visited[N] = True

if N >= K:
    print(N-K)
else:
    while True:
        pos = queue.popleft()
        if pos == K:
            print(array[pos])
            break
        else:
            new_pos1 = pos+1
            new_pos2 = pos-1
            new_pos3 = pos*2

            if new_pos1 <= 100000 and visited[new_pos1] == False:
                queue.append(new_pos1)
                array[new_pos1] = array[pos]+1
                visited[new_pos1] = True
            if new_pos2 >= 0 and visited[new_pos2] == False:
                queue.append(new_pos2)
                array[new_pos2] = array[pos]+1
                visited[new_pos2] = True
            if new_pos3 <= 100000 and visited[new_pos3] == False:
                queue.append(new_pos3)
                array[new_pos3] = array[pos]+1
                visited[new_pos3] = True