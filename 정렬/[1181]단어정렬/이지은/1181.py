import sys

N = int(sys.stdin.readline())
wordDic = {}
arr = []

for i in range(N):
    word = sys.stdin.readline()
    if word not in wordDic:
        wordDic[word] = len(word)

# 최종 출력
wordDic = sorted(wordDic.items())
wordDic = sorted(wordDic, key=lambda x: x[1])

for i in wordDic:
    sys.stdout.write(str(i[0]))
