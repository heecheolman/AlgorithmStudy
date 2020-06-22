import sys

N = int(sys.stdin.readline())

stack = []


def is_empty(s):
    return len(s) == 0


for _ in range(N):
    command = sys.stdin.readline().split()
    operator = command[0]

    if operator == 'push':
        stack.append(command[1])
    elif operator == 'pop':
        print(-1 if is_empty(stack) else stack.pop())
    elif operator == 'top':
        print(-1 if is_empty(stack) else stack[-1])
    elif operator == 'size':
        print(len(stack))
    elif operator == 'empty':
        print(1 if len(stack) == 0 else 0)
