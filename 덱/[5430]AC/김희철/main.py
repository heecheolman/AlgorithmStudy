from sys import stdin

T = int(stdin.readline())


def compile_ac_lang(p, n, seq):
    front = 0
    back = len(seq) - 1
    mode = 'front'

    if p.count('D') > n:
        print('error')
        return

    for op in p:
        if op == 'R':
            mode = 'back' if mode == 'front' else 'front'
        elif op == 'D':
            if mode == 'front':
                front += 1
            elif mode == 'back':
                back -= 1

    remain = []
    for index in range(front, back + 1):
        remain.append(seq[index])

    if mode == 'back':
        remain.reverse()

    print('[' + ','.join(str(v) for v in remain) + ']')


for _ in range(T):
    p = list(stdin.readline().strip())
    n = int(stdin.readline())
    seq = stdin.readline().strip()[1:-1].split(',')

    compile_ac_lang(p, n, seq)

