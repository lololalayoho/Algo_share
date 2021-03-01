word1 = str(input())
word2 = str(input())
dp = [[0 for i in range(len(word1)+1)] for j in range(len(word2)+1)]
dp_word = [['' for index1 in range(len(word1)+1)] for index2 in range(len(word2)+1)]
for i in range(1,len(word1)+1):
    for j in range(1,len(word2)+1):
        if word1[i-1]==word2[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            dp[i][j] = max(dp[i-1][j],dp[i][j-1])
answer = ''
while
print(dp[len(word1)][len(word2)])
print(dp_word[len(word1)][len(word2)])

ACAYKP
CAPC