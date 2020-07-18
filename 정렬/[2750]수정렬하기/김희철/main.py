import sys

numbers = []
N = int(sys.stdin.readline())

for _ in range(N):
    numbers.append(int(sys.stdin.readline()))

for i in range(0, len(numbers)):
    for j in range(0, len(numbers) - i - 1):
        if numbers[j] > numbers[j+1]:
            numbers[j+1], numbers[j] = numbers[j], numbers[j+1]


for num in numbers:
    print(num)
