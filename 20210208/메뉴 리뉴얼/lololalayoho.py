from itertools import combinations
def make_Candidate(orders):
    orderCandidate = sorted(list(set(orders)))
    return orderCandidate

def make_Course(j,orders):
    cnt = 0
    word = ''
    for k in orders:
        if len(list(j)) <= len(list(k)):
            add = set(list(j)) & set(list(k))
            if len(list(add)) == len(set(list(j))):
                cnt = cnt + 1
    if cnt >= 2:
        answer = sorted(list(j))
        for k in answer:
            word = word + k
    return word,cnt

def chooseAnswer(makecourses,course):
    answer = []
    for i in course:
        max_value = 0
        for j in makecourses:
            if len(j[0]) == i and max_value < int(j[1]):
                max_value = int(j[1])
        for j in makecourses:
            if int(j[1]) == max_value and len(j[0]) == i:
                answer.append(j[0])
    return sorted(answer)

def solution(orders, course):
    order = []
    answer = []
    total_combi = []
    makecourses = []
    for i in orders:
        words = sorted(list(set(i)))
        word = ''
        for j in words:
            word = word + j
        order.append(word)
    for i in order:
        orderCandidate = make_Candidate(i)
        for j in course:
            if len(orderCandidate) < j:
                break
            else:
                listcombi = set(list(combinations(orderCandidate,j)))
                for k in set(listcombi):
                    if k not in total_combi:
                        total_combi.append(k)
                        makecourse,cnt = make_Course(k,order)
                        if cnt >=2:
                            makecourses.append((makecourse,cnt))
    answer = chooseAnswer(makecourses,course)
    return answer