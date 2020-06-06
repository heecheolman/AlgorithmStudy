N, M = map(int, input().split())

card_numbers = [int(num) for num in input().split()]


def draw():
    result = []
    for a in range(N - 2):
        for b in range(a + 1, N - 1):
            for c in range(b + 1, N):
                value = card_numbers[a] + card_numbers[b] + card_numbers[c]
                if value <= M:
                    result.append(value)

    return max(result)


print(draw())
