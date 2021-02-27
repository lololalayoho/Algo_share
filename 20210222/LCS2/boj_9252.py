# LCS2 https://www.acmicpc.net/problem/9252

str1 = '0'+input()
str2 = '0'+input()

LCS_len = [[] for i in range(len(str2))]
LCS_str = [[] for i in range(len(str2))]

for i in range(len(str2)):
    if str2[i] == '0':
        for j in range(len(str1)):
            LCS_len[i].append(0)
            LCS_str[i].append('0')
    else:
        for k in range(len(str1)):
            if str1[k] == '0':
                LCS_len[i].append(0)
                LCS_str[i].append('0')
            else:
                if str2[i] != str1[k]:
                    LCS_len[i].append(max(LCS_len[i][k-1], LCS_len[i-1][k]))
                    if LCS_len[i][k-1] >= LCS_len[i-1][k]:
                        LCS_str[i].append(LCS_str[i][k-1])
                    elif LCS_len[i][k-1] < LCS_len[i-1][k]:
                        LCS_str[i].append(LCS_str[i-1][k])
                elif str2[i] == str1[k]:
                    LCS_len[i].append(LCS_len[i-1][k-1] + 1)
                    LCS_str[i].append(LCS_str[i-1][k-1] + str2[i])

def getPos():
    count = 0
    for i in range(len(str2)):
        for j in range(len(str1)):
            if LCS_len[i][j] >= count:
                count = LCS_len[i][j]

    return (i, j)

result = getPos()

if LCS_len[result[0]][result[1]] == 0:
    print(0)
    exit
else:
    print(LCS_len[result[0]][result[1]])
    print(LCS_str[result[0]][result[1]][1:])