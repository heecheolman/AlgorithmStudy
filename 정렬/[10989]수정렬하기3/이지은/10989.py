import sys

# 딕셔너리 사용 예)
# 오답인데 안되는 이유를 찾고싶습니다..찾아내겠습니다...
# python3: 시간 초과
# pypy3: 메무리 초과
# if __name__ == '__main__':
#     N = int(sys.stdin.readline())
#     dic = {}
#
#     for i in range(N):
#         value = int(sys.stdin.readline())
#         if value in dic:
#             dic[value] += 1
#         else:
#             dic[value] = 1
#
#     for sortArr in sorted(list(dic.items())):
#         for i in range(sortArr[1]):
#             sys.stdout.write(str(sortArr[0]) + '\n')


if __name__ == '__main__':
    N = int(sys.stdin.readline())
    arr = [0] * 10001

    for i in range(N):
        value = int(sys.stdin.readline())
        arr[value] += 1

    for i in range(10001):
        if arr[i] != 0:
            for j in range(arr[i]):
                sys.stdout.write(str(i) + '\n')
