from sys import stdin

counting = [0] * 10001
N = int(stdin.readline())

for _ in range(N):
    counting[int(stdin.readline())] += 1

for i in range(10001):
    for j in range(counting[i]):
        print(i)