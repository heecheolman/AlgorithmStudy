import sys
import operator

N = int(sys.stdin.readline())

arr = []
dic = {}
current = 0

for i in range(N):
    current = int(sys.stdin.readline())
    # 중앙값을 위한 arr
    arr.append(current)
    # 최빈값을 위한 dic 구성
    if current in dic:
        dic[current] += 1
    else:
        dic[current] = 1

sortArr = sorted(arr)
# 최빈값 추출
maxValue = max(dic.items(), key=operator.itemgetter(1))[1]
# 최빈값과 같은 값을 가진 배열 생성
filterDic = {key: value for (key, value) in dic.items() if value == maxValue}
maxKeys = sorted(list(filterDic.keys()))


# 출력
# 산술평균 / 소수점 이하 첫번째 자리에서 반올림
sys.stdout.write(str(round(sum(arr) / N)) + '\n')
# 중앙값
sys.stdout.write(str(sortArr[round((N - 1) / 2)]) + '\n')
# 최빈값 / 여러개의 경우 최빈값 중 두번째로 작은 값
sys.stdout.write(str(maxKeys[1] if len(maxKeys) > 1 else maxKeys[0]) + '\n')
# 범위
sys.stdout.write(str(sortArr[-1] - sortArr[0]) + '\n')
