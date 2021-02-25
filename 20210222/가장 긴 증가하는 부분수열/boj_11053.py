# 가장 긴 증가하는 부분수열 https://www.acmicpc.net/problem/11053

N = int(input())

array = list(map(int, input().split()))
dp = [1 for i in range(N)]
temp_list = list()

# 다시보니 코드가 이해가 안돼 다시품
for i in range(N):
    for j in range(i):
        if array[i] > array[j]:
            temp_list.append(dp[j]+1)
            temp = max(temp_list)
            dp[i] = temp
    temp_list.clear()

print(max(dp))

# 이 코드도 맞는 코드
# for i in range(N):
#     for j in range(i):
#         if array[i] > array[j] and dp[j] + 1 > dp[i]:
#             dp[i] = dp[j] + 1

# print(max(dp))

# 완전탐색 풀이 - 시간초과
# for i in range(N):
#     if i != N-1:
#         for j in range(i+1, N):
#             temp_list.append(array[i])
#             for k in range(j, N):
#                 if array[k] > temp_list[-1]:
#                     temp_list.append(array[k])
#             temp = len(temp_list)
#             if count <= temp:
#                 count = temp
#             temp_list.clear()
#     else:
#         temp_list.append(array[i])
#         temp = len(temp_list)
#         if count <= temp:
#             count = temp
#         temp_list.clear()
# print(count)


