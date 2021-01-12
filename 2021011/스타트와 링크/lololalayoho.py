from itertools import combinations

def calcul_score(scoreboard,players,N):
    max_gap = 999999999
    combi = combinations(players,N//2)
    for think in list(set(combi)):
        sum1 = 0 #visit값이 1인 애들을 더할 변수
        sum2 = 0 #visit값이 0인 애들을 더할 변수
        zero = []
        for i in range(N):
            if i not in list(think):
                zero.append(i)
        for i in list(think):
            for j in list(think):
                sum1 = sum1 + scoreboard[i][j]
        for i in zero:
            for j in zero:
                sum2 = sum2 + scoreboard[i][j]
        if max_gap > abs(sum1-sum2):
            max_gap = abs(sum1-sum2)
    return max_gap

players = []
N = int(input())
scoreboard = [list(map(int,input().split())) for _ in range(N)]
for i in range(N):
    players.append(i)
print(calcul_score(scoreboard,players,N))
