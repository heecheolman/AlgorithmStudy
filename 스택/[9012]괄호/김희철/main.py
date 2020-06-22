import sys

N = int(sys.stdin.readline())


class Stack:
    def __init__(self):
        self.stack = []

    def push(self, value):
        self.stack.append(value)

    def pop(self):
        return self.stack.pop()

    @property
    def empty(self):
        return len(self.stack) == 0

    def top(self):
        return -1 if self.empty else self.stack[-1]


for _ in range(N):
    input_ps = sys.stdin.readline()
    s = Stack()

    for ps in input_ps:
        if ps == '(':
            s.push('(')
        elif ps == ')':
            if s.top() == '(':
                s.pop()
            else:
                s.push(ps)

    print('YES') if s.empty else print('NO')
