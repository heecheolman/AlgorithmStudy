from sys import stdin

numbers = []
N = int(stdin.readline())

for _ in range(N):
    numbers.append(int(stdin.readline()))


def quick_sort(array, left, right):
    if left >= right:
        return

    pivot = array[(left + right) // 2]
    start, end = left, right

    while start <= end:
        while array[start] < pivot:
            start += 1
        while array[end] > pivot:
            end -= 1

        if start <= end:
            array[start], array[end] = array[end], array[start]
            start += 1
            end -= 1

    quick_sort(array, left, end)
    quick_sort(array, start, right)

    return array


for value in quick_sort(numbers, 0, len(numbers) - 1):
    print(value)
