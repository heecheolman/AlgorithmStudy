import sys


class CircularQueue:
    def __init__(self, data):
        self.queue = data
        self.tail = len(data) - 1
        self.head = 0
        self.cur = 0

    @property
    def is_empty(self):
        return self.head == -1

    @property
    def size(self):
        return len(self.queue)

    def get_cur_item(self):
        return self.queue[self.cur]

    def next(self):
        self.cur = (self.cur + 1) % self.size


def get_next_people(people, at):
    circular_queue = CircularQueue(people)
    count = 1

    while count != at:
        circular_queue.next()
        count += 1

    next_queue = circular_queue.queue[circular_queue.cur+1:] + circular_queue.queue[:circular_queue.cur]

    return [circular_queue.get_cur_item(), next_queue]


def formatting(seq):
    str_sequence = ''
    for index, num in enumerate(seq):
        if index != len(seq)-1:
            str_sequence += str(num) + ', '
        else:
            str_sequence += str(num)
    return '<' + str_sequence + '>'


def get_sequence(at):
    sequence = []
    people = []
    for x in range(N):
        people.append(x + 1)

    while True:
        person, next_people = get_next_people(people, at)
        if not next_people:
            sequence.append(person)
            break
        sequence.append(person)
        people = next_people

    str_sequence = ''
    for index, num in enumerate(sequence):
        if index != len(sequence)-1:
            str_sequence += str(num) + ', '
        else:
            str_sequence += str(num)

    return formatting(sequence)


N, K = map(int, sys.stdin.readline().split())

print(get_sequence(K))
