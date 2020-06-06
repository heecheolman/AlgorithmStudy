N, M = map(int, input().split())

card_numbers = [int(num) for num in input().split()]


def draw():
    result = 0
    for a_index, a in enumerate(card_numbers):
        for b_index, b in enumerate(card_numbers[a_index + 1:]):
            for c_index, c in enumerate(card_numbers[a_index + 2:]):
                if a != b and b != c and c != a:
                    blackjack = a + b + c
                    if result < blackjack <= M:
                        result = blackjack
    return result


print(draw())
