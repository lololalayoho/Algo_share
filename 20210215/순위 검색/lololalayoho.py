# https://programmers.co.kr/learn/courses/30/lessons/72412
infos = []
values = []
visit = [0 for i in range(4)]
def make_order(word, start, cnt, totalcnt):
    global infos, values, visit
    if cnt == totalcnt:
        sentence = ""
        for i in range(4):
            if visit[i] == 1:
                sentence = sentence + word[i]
            else:
                sentence = sentence + "-"
        if sentence not in infos:
            infos.append(sentence)
            value = [int(word[4])]
            values.append(value)
        else:
            info_index = infos.index(sentence)
            values[info_index].append(int(word[4]))
    else:
        for i in range(start, 4):
            if visit[i] == 0:
                visit[i] = 1
                make_order(word, i + 1, cnt + 1, totalcnt)
                visit[i] = 0


def solution(info, query):
    answer = []
    for i in info:
        word = []
        word.append(i.split(' ')[0])
        word.append(i.split(' ')[1])
        word.append(i.split(' ')[2])
        word.append(i.split(' ')[3])
        word.append(i.split(' ')[4])
        for j in range(5):
            make_order(word, 0, 0, j)
    kakao = []
    for index, i in enumerate(infos):
        kakao.append((i, values[index]))
    kakaoinfo = dict(kakao)
    for ka in kakaoinfo.values():
        ka.sort()
    for i in query:
        sentence = ""
        word = []
        word.append(i.split(' ')[0])
        word.append(i.split(' ')[2])
        word.append(i.split(' ')[4])
        word.append(i.split(' ')[6])
        word.append(i.split(' ')[7])
        for j in range(4):
            sentence = sentence + word[j]
        if sentence in infos:
            data = kakaoinfo[sentence]
            if len(data) > 0:
                start, end = 0, len(data)
                while start != end and start != len(data):
                    if data[(start + end) // 2] >= int(word[4]):
                        end = (start + end) // 2
                    else:
                        start = (start + end) // 2 + 1
                answer.append(len(data) - start)
            else:
                answer.append(0)
        else:
            answer.append(0)
    return answer