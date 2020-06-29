import sys


N = int(sys.stdin.readline())

queue = []
head = 0
tail = 0

for _ in range(N):
    command = sys.stdin.readline().split()
    operator = command[0]

    if operator == 'push':
        queue.append(command[1])
        tail += 1
    elif operator == 'pop':
        if head == tail:
            print(-1)
        else:
            pop_value = queue[head]
            head += 1
            print(pop_value)
    elif operator == 'front':
        if head == tail:
            print(-1)
        else:
            print(queue[head])
    elif operator == 'back':
        if head == tail:
            print(-1)
        else:
            print(queue[tail-1])
    elif operator == 'empty':
        print(1 if head == tail else 0)
    elif operator == 'size':
        print(tail - head)
