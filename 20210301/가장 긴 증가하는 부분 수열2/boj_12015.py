# 가장 긴 증가하는 부분수열 2 https://www.acmicpc.net/problem/12015

N = int(input())

array = list(map(int, input().split()))

dp = []
dp.append(float('-inf'))

def BinarySearch(par_array, start_idx, end_idx, target):
    if start_idx > end_idx:
        return start_idx

    mid = (start_idx + end_idx) // 2

    if par_array[mid] == target:
        return mid

    elif par_array[mid] > target:
        return BinarySearch(par_array, start_idx, mid-1, target)
    
    elif par_array[mid] < target:
        return BinarySearch(par_array, mid+1, end_idx, target)

for arr in array:
    if arr > dp[-1]:
        dp.append(arr)

    elif arr == dp[-1]:
        continue

    elif arr < dp[-1]:
        temp = BinarySearch(dp, 0, len(dp)-1, arr)
        dp[temp] = arr
    
print(len(dp)-1)

# from bisect import bisect_left

# N = int(input())

# array = list(map(int, input().split()))

# dp = []
# dp.append(float('-inf'))

# for arr in array:
#     if arr > dp[-1]:
#         dp.append(arr)

#     elif arr < dp[-1]:
#         temp_idx = bisect_left(dp, arr)
#         dp[temp_idx] = arr

#     elif arr == dp[-1]:
#         continue
    
# del dp[0]

# print(len(dp))
# for i in dp:
#     print(i, end=' ')