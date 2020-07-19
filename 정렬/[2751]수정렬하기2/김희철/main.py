from sys import stdin

numbers = []
N = int(stdin.readline())

for _ in range(N):
    numbers.append(int(stdin.readline()))


def merge_sort(array):
    length = len(array)
    if length == 1:
        return array

    half_index = length // 2
    left = array[:half_index]
    right = array[half_index:]

    a = merge_sort(left)
    b = merge_sort(right)

    return merge(a, b)


def merge(left, right):
    left_cur = 0
    right_cur = 0
    left_end = len(left) - 1
    right_end = len(right) - 1

    sorted_list = []

    while left_cur <= left_end and right_cur <= right_end:
        if left[left_cur] < right[right_cur]:
            sorted_list.append(left[left_cur])
            left_cur += 1
        else:
            sorted_list.append(right[right_cur])
            right_cur += 1

    if left_cur <= left_end:
        sorted_list = sorted_list + left[left_cur:]

    if right_cur <= right_end:
        sorted_list = sorted_list + right[right_cur:]

    return sorted_list


for value in merge_sort(numbers):
    print(value)
