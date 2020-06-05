N = int(input())

big_list = []

for n in range(N):
    weight, height = map(int, input().split())
    big_list.append([weight, height, N])


def create_big_rank():
    for origin in big_list:
        rank = 1
        for target in big_list:
            if origin[0] < target[0] and origin[1] < target[1]:
                rank += 1
        print(rank, end=' ')


create_big_rank()
