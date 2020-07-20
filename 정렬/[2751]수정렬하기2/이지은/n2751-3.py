import sys

N = int(sys.stdin.readline())
arr = []

for i in range(N):
    arr.append(int(sys.stdin.readline()))

sortArr = sorted(arr)

# 최종 출력
for i in sortArr:
    sys.stdout.write(str(i) + '\n')

