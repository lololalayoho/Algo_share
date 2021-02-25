# 퇴사 https://www.acmicpc.net/problem/14501

time_cost = list()
price = list()
dp = list()

result = 0

N = int(input())

for _ in range(N):
    T, P = map(int, input().split())
    time_cost.append(T)
    price.append(P)


