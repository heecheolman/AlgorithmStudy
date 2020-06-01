N = int(input())


def move(num, start, bridge, end):
    if num == 1:
        print(start, end)
        return
    move(num - 1, start, end, bridge)
    print(start, end)
    move(num - 1, bridge, start, end)


print((2 ** N) - 1)
move(N, 1, 2, 3)
