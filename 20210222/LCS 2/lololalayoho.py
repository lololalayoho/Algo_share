# 런타임 에러 발생
word1 = str(input())
word2 = str(input())
dp = [[0 for i in range(len(word1)+1)] for j in range(len(word2)+1)]
dp_word = [['' for i in range(len(word1)+1)] for j in range(len(word2)+1)]
for i in range(1,len(word1)+1):
    for j in range(1,len(word2)+1):
        if word1[i-1]==word2[j-1]:
            dp[i][j] = dp[i-1][i-1] + 1
            dp_word[i][j] = dp_word[i-1][j-1] + word2[j-1]
        else:
            if dp[i-1][j] < dp[i][j-1] :
                dp[i][j] = dp[i][j-1]
                dp_word[i][j] = dp_word[i][j-1]
            else:
                dp[i][j] = dp[i-1][j]
                dp_word[i][j] = dp_word[i-1][j]
print(dp[-1][-1])
print(dp_word[-1][-1])