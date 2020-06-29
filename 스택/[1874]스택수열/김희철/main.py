import sys


class Stack:
    stack = []

    def __init__(self, data):
        self.stack = data

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
        if self.is_empty:
            return -1
        else:
            return self.stack.pop()


N = int(sys.stdin.readline())

sequence = []
source = []

for _ in range(N):
    source.append(int(sys.stdin.readline()))

sequence = source.copy()
source.sort()


def get_stack_seq(seq, source):
    source.reverse()
    t = Stack([])
    s = Stack(source)
    result = Stack([])
    output = []

    for target_num in seq:
        while True:
            if t.top() == target_num or s.is_empty:
                break
            t.push(s.pop())
            output.append('+')

        result.push(t.pop())
        output.append('-')

    if seq == result.stack:
        for str in output:
            print(str)
    else:
        print('NO')


get_stack_seq(sequence, source)
