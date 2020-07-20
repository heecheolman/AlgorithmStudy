

N = int(input())
arr = []


# 버블 정렬
def bubble():
    for i in range(N):
        for j in range(N - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]


# 선택 정렬
def selection():
    for i in range(N):
        min_index = i
        for j in range(i + 1, N):
            if arr[min_index] > arr[j]:
                min_index = j
        arr[min_index], arr[i] = arr[i], arr[min_index]


# 병합 정렬
def merge(array):
    if len(array) <= 1:
        return array
    middle = round(len(array)/2)
    left = merge(array[:middle])
    right = merge(array[middle:])
    return merge_sort(left, right)


def merge_sort(left_arr, right_arr):
    left_idx = 0
    right_idx = 0
    new_array = []
    while left_idx < len(left_arr) or right_idx < len(right_arr):
        if left_idx < len(left_arr) and right_idx < len(right_arr):
            if left_arr[left_idx] <= right_arr[right_idx]:
                new_array.append(left_arr[left_idx])
                left_idx += 1
            else:
                new_array.append(right_arr[right_idx])
                right_idx += 1
        elif left_idx < len(left_arr):
            new_array.append(left_arr[left_idx])
            left_idx += 1
        elif right_idx < len(right_arr):
            new_array.append(right_arr[right_idx])
            right_idx += 1
    return new_array


if __name__ == '__main__':
    for i in range(N):
        arr.append(int(input()))

    # 버블 정렬
    bubble()

    # 선택 정렬
    # selection()

    # 병합 정렬
#     arr = merge(arr)

    # 최종 출력
    for i in arr:
        print(i)
