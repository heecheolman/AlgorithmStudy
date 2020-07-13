

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
        for j in range(i, N):
            if arr[i] > arr[j]:
                arr[i], arr[j] = arr[j], arr[i]


def main():
    for i in range(N):
        arr.append(int(input()))

    # 버블 정렬
    # bubble()

    # 선택 정렬
    selection()

    # 최종 출력
    for i in arr:
        print(i)


main()
