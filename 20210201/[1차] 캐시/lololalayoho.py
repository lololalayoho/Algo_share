def solution(catcheSize,cities):
    answer = 0
    if catcheSize==0:
        answer = 5 * len(cities)
    else:
        page = []
        index = 0
        for i in cities:
            if i.upper() in page:
                answer = answer + 1
                page.pop(page.index(i.upper()))
                page.append(i.upper())
            else:
                if len(page) < catcheSize:
                    page.append(i.upper())
                else:
                    page.pop(0)
                    page.append(i.upper())
                answer = answer + 5
    return answer