import sys


class Stack:
    stack = []

    def __init__(self):
        self.stack = []

    @property
    def is_empty(self):
        return self.len == 0

    @property
    def len(self):
        return len(self.stack)

    def push(self, value):
        self.stack.append(value)

    def top(self):
        return -1 if self.is_empty else self.stack[-1]

    def pop(self):
        return -1 if self.is_empty else self.stack.pop()


def check_line(line):
    if line == '.':
        return True

    s = Stack()
    for char in line:
        if char == '(' or char == '[':
            s.push(char)
        elif char == ')':
            if s.top() == '(':
                s.pop()
            else:
                return False
        elif char == ']':
            if s.top() == '[':
                s.pop()
            else:
                return False

    return s.len == 0


while True:
    line = sys.stdin.readline().splitlines()[0]
    if line == '.':
        break
    print('yes') if check_line(line) else print('no')

