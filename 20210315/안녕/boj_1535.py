# 안녕 https://www.acmicpc.net/problem/1535

"""
백트래킹 재귀를 이용한 풀이
"""
n = int(input())

costs = list(map(int, input().split()))
joys = list(map(int, input().split()))

life = 100
result = 0

# 현재 인덱스, 현재 기쁨, 현재 라이프를 인자로 연산하는 재귀함수
def Recursion(idx, cur_joy, cur_life):
    global result

    # 종료조건 : 라이프가 0이하일 때
    if cur_life <= 0:
        # 이전의 기쁨을 결과로 리턴
        prev_joy = cur_joy-joys[idx-1]
        if prev_joy > result:
            result = prev_joy
        return

    # 종료조건 : 모든 사람을 탐색했을 경우
    if idx == n:
        if cur_joy > result:
            result = cur_joy
        return

    # 현재 사람을 선택할 경우
    Recursion(idx+1, cur_joy+joys[idx], cur_life-costs[idx])
    # 현재 사람을 선택하지 않을 경우
    Recursion(idx+1, cur_joy, cur_life)

Recursion(0, 0, life)
print(result)

"""
2차원 DP를 이용한 풀이
"""

n = int(input())

costs = [0]
joys = [0]

cost = list(map(int, input().split()))
joy = list(map(int, input().split()))

costs += cost
joys += joy

costs_limit = 99

dp = [[0] * 100 for _ in range(n+1)]

for i in range(1, n+1):
    for j in range(100):
        if costs[i] > j:
            dp[i][j] = dp[i-1][j]
        else:
            dp[i][j] = max(dp[i-1][j-costs[i]] + joys[i], dp[i-1][j])

print(dp[n][costs_limit])
