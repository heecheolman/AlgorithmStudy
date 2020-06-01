N, M = map(int, input().split())

card_numbers = [int(num) for num in input().split()]


def draw():
    result = 0
    for a_index, a in enumerate(card_numbers):
        for b_index, b in enumerate(card_numbers):
            for c_index, c in enumerate(card_numbers):
                if a_index != b_index and b_index != c_index and c_index != a_index:
                    blackjack = a + b + c
                    if result < blackjack <= M:
                        result = blackjack
    return result


print(draw())
