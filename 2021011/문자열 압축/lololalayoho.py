def push_word(s,size):
    word = ""
    return word + s[:size]

def solution(s):
    answer = 999999999
    for j,hello in enumerate(s):
        i = j+1

        sentence = ""
        index = 0
        while index+i <= len(s) and int(len(s) - index) >= i:
            word = push_word(s[index:], i)
            cnt = 0
            if s[index:index+i]==word:
                while s[index:index+i]==word:
                    index = index + i
                    cnt = cnt + 1
                if cnt==1:
                    sentence = sentence + word
                else:
                    sentence = sentence + str(cnt) + word
        sentence = sentence + s[index:]
        if len(sentence) < answer:
            answer = len(sentence)
    return answer