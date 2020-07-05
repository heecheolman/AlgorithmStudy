import sys


class Deque:
    def __init__(self, data):
        self.data = data

    def front(self):
        return self.data[0]

    def pop_front(self):
        return self.data.pop(0)

    def pop_back(self):
        return self.data.pop()

    def push_front(self, value):
        self.data.insert(0, value)

    def push_back(self, value):
        self.data.append(value)

    def left(self):
        self.push_back(self.pop_front())

    def right(self):
        self.push_front(self.pop_back())

    def size(self):
        return len(self.data)

    def get_item_index(self, value):
        return self.data.index(value)


N, M = map(int, sys.stdin.readline().split())
target_list = list(map(int, sys.stdin.readline().split()))

sequence = []
for x in range(N):
    sequence.append(x+1)

deque = Deque(sequence)
process_count = 0

for target in target_list:
    while True:
        if deque.front() == target:
            deque.pop_front()
            break

        if deque.get_item_index(target) < (deque.size() / 2):
            deque.left()
            process_count += 1
        else:
            deque.right()
            process_count += 1

print(process_count)