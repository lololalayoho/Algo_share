def changeMelody(Infos):
    melodies = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B']
    Info = ""
    for index, i in enumerate(Infos):
        melody = ""
        if i != '#':
            if index + 1 < len(Infos):
                if Infos[index + 1] == '#':
                    melody = Infos[index] + '#'
                else:
                    melody = Infos[index]
            else:
                melody = i

            if melody in melodies:
                if (melodies.index(melody) == 10):
                    Info = Info + 'A'
                elif (melodies.index(melody) == 11):
                    Info = Info + 'B'
                else:
                    Info = Info + str(melodies.index(melody))
    return Info


# 시간의 길이를 바꾸는 함수
def changeTimes(musicinfos):
    MusicInfos = []
    for i in musicinfos:
        startTime = i.split(',')[0]
        lastTime = i.split(',')[1]
        # 시간을 분으로 바꾸기
        startTimeMinute = int(startTime.split(':')[0]) * 60 + int(startTime.split(':')[1])
        lasatTimeMinute = int(lastTime.split(':')[0]) * 60 + int(lastTime.split(':')[1])
        # melody를 index로 바꾸기 #처리를 위해
        melody = changeMelody(i.split(',')[3])
        # 시간의 길이 구하기
        MusicInfo = str(int(lasatTimeMinute) - int(startTimeMinute)) + "," + i.split(',')[2] + "," + melody
        MusicInfos.append(MusicInfo)
    return MusicInfos


# 음악을 체크하는 함수
def checkMusic(m, MusicInfos):
    Time = -1
    Music = ""
    for i in MusicInfos:
        musicTime = i.split(',')[0]
        melody = i.split(',')[2]
        melody_sentence = ""
        index = 0
        # musicTime만큼 melody의 index 값을 더하기 위함
        while len(melody_sentence) < int(musicTime):
            melody_sentence = melody_sentence + melody[index]
            index = index + 1
            if index == len(melody):
                index = 0
        if m in melody_sentence:
            if Time < int(musicTime):
                Time = int(musicTime)
                Music = i.split(',')[1]
        if Time == -1:
            Music = "(None)"
    return Music


def solution(m, musicinfos):
    MusicInfos = []  # 변환된 시간을 저장할 배열
    MusicInfos = changeTimes(musicinfos)
    Listen = changeMelody(m)
    return checkMusic(Listen, MusicInfos)