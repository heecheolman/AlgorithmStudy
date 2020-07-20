import sys

numbers = []
N = int(sys.stdin.readline())

for _ in range(N):
    numbers.append(int(sys.stdin.readline()))

for i in range(1, len(numbers)):
    select = numbers[i]
    targetIndex = i - 1

    while targetIndex >= 0 and numbers[targetIndex] > select:
        numbers[targetIndex + 1] = numbers[targetIndex]
        targetIndex -= 1

    numbers[targetIndex + 1] = select

for num in numbers:
    print(num)
