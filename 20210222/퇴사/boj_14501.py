# 퇴사 https://www.acmicpc.net/problem/14501 씨발

time_cost = list()
price_earn = list()
max_val = 0

# result = 0

N = int(input())

dp = [0 for i in range(N+1)]

for _ in range(N):
    T, P = map(int, input().split())
    time_cost.append(T)
    price_earn.append(P)

# dp[i] = i일부터 마지막까지 상담 시 얻을 수 있는 최대 이득
# dp[i] = p[i] + dp[i+t[i]]

# N일부터 1일까지 거꾸로 계산
for i in range(N-1, -1, -1):
    temp = i + time_cost[i]
    if temp <= N:
        dp[i] = max(price_earn[i] + dp[temp], max_val)
        max_val = dp[i]
    else:
        dp[i] = max_val

print(max_val)