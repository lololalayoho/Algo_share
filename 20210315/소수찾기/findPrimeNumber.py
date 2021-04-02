from itertools import permutations

def Prime(toTest):
    if toTest == 0 or toTest == 1:
        return False
    for i in range(2, toTest):
        if toTest%i == 0:
            return False
    return True

def PrimeArray(array, count):
    for arrays in array:
        if Prime(arrays):
            count += 1
    return count

def assembleTup(tups:list):
    temp = ''
    for tup in range(len(tups)):
        temp += tups[tup]
    return temp

def solution(numbers):
    array = []
    count = 0
    result = 0
    length = len(numbers)

    for i in range(1, length+1):
        tups = list(permutations(numbers, i))
        for tup in tups:
            if int(assembleTup(tup)) not in array:
                array.append(int(assembleTup(tup)))

    return PrimeArray(array, count)