import sys


class Queue:
    def __init__(self, data):
        self.queue = data
        self.head = 0
        self.tail = len(data)

    @property
    def is_last_card(self):
        return self.tail - self.head == 1

    @property
    def front(self):
        return self.queue[self.head]

    def pop(self):
        pop_value = self.queue[self.head]
        self.head += 1
        return pop_value

    def push(self, data):
        self.queue.append(data)
        self.tail += 1


def get_last_card(cards):
    deck = Queue(cards)

    while True:
        if deck.is_last_card:
            return deck.front
        deck.pop()
        deck.push(deck.pop())


N = int(sys.stdin.readline())
cards = []

for num in range(N):
    cards.append(num + 1)

print(get_last_card(cards))
