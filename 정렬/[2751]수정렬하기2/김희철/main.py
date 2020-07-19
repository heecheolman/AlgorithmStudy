from sys import stdin

numbers = []
N = int(stdin.readline())

for _ in range(N):
    numbers.append(int(stdin.readline()))


def quick_sort(array):
    length = len(array)
    if length <= 1:
        return array

    pivot = array[length // 2]

    small = []
    big = []
    equal = []

    for v in array:
        if v < pivot:
            small.append(v)
        elif v > pivot:
            big.append(v)
        else:
            equal.append(v)

    return quick_sort(small) + equal + quick_sort(big)


for value in quick_sort(numbers):
    print(value)
