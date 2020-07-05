import sys


N = int(sys.stdin.readline())


class Deque:
    def __init__(self):
        self.data = []

    def push_front(self, value):
        self.data.insert(0, value)

    def push_back(self, value):
        self.data.append(value)

    def front(self):
        if self.empty():
            return -1
        return self.data[0]

    def back(self):
        if self.empty():
            return -1
        return self.data[-1]

    def empty(self):
        return self.size() == 0

    def size(self):
        return len(self.data)

    def pop_front(self):
        if self.empty():
            return -1
        return self.data.pop(0)

    def pop_back(self):
        if self.empty():
            return -1
        return self.data.pop()


deque = Deque()

for _ in range(N):
    command = sys.stdin.readline().split()
    operator = command[0]

    if operator == 'push_back':
        deque.push_back(command[1])
    elif operator == 'push_front':
        deque.push_front(command[1])
    elif operator == 'pop_back':
        print(deque.pop_back())
    elif operator == 'pop_front':
        print(deque.pop_front())
    elif operator == 'front':
        print(deque.front())
    elif operator == 'back':
        print(deque.back())
    elif operator == 'size':
        print(deque.size())
    elif operator == 'empty':
        print(1 if deque.empty() else 0)