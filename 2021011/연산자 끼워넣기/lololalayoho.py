from itertools import permutations
def inital(N,num,cal): #초기화
    calculate = []
    numbers = []
    for i in range(N):
        numbers.append(num.split(" ")[i])
    for i in range(4):
        if i == 0:
            for j in range(int(cal.split(" ")[0])):
                calculate.append("+")
        elif i == 1:
            for j in range(int(cal.split(" ")[1])):
                calculate.append("-")
        elif i == 2:
            for j in range(int(cal.split(" ")[2])):
                calculate.append("*")
        elif i == 3:
            for j in range(int(cal.split(" ")[3])):
                calculate.append("/")
    return numbers,calculate

def check(numbers,calculate): #순열을 이용하여 최댓값, 최솟값 구하기
    max_value = int(-1000000000)
    min_value = int(1000000000)
    permu = permutations(calculate,len(calculate))
    for cal in list(set(permu)):
        sum = int(numbers[0])
        for index, i in enumerate(list(cal)):
            if i == "+":
                sum = sum + int(numbers[index + 1])
            elif i == "-":
                sum = sum - int(numbers[index + 1])
            elif i == "*":
                sum = sum * int(numbers[index + 1])
            elif i == "/":
                sum =  int(sum / int(numbers[index + 1]))
            if sum >= 1000000000 or sum <= -1000000000:
                break
        if max_value < sum:
            max_value = sum
        if min_value > sum:
            min_value = sum
    return max_value,min_value

N = int(input())
numbers = []
calculate = []
num = input()
cal = input()
numbers,calculate = inital(N,num,cal)
max_value,min_value = check(numbers,calculate)
print(max_value)
print(min_value)