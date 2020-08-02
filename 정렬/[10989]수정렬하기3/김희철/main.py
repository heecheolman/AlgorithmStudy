from sys import stdin

numbers = []
N = int(stdin.readline())

for _ in range(N):
    numbers.append(int(stdin.readline()))

max_num = max(numbers)
min_num = min(numbers)

counting = [0 for i in range(len(numbers))]
output = [-1 for i in range(len(numbers))]

for n in numbers:
    counting[n-min_num]+=1

for i in range(1, len(counting)):
    counting[i] += counting[i - 1]

for num in reversed(numbers):
    output[counting[num-min_num] - 1] = num
    counting[num - min_num] -= 1

for n in output:
    print(n)