import sys

numbers = []
N = int(sys.stdin.readline())

for _ in range(N):
    numbers.append(int(sys.stdin.readline()))

for i in range(0, len(numbers)):
    minIndex = i
    for j in range(i, len(numbers)):
        if numbers[j] < numbers[minIndex]:
            minIndex = j
    numbers[i], numbers[minIndex] = numbers[minIndex], numbers[i]


for num in numbers:
    print(num)