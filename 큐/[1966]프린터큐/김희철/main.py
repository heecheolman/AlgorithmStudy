from sys import stdin


class Queue:
    def __init__(self, data):
        self.queue = data
        self.head = 0
        self.tail = len(data) - 1


def next_print(document_list):
    q = Queue(document_list)
    max_priority = 0
    max_pos = 0
    for cur in range(q.head, q.tail + 1):
        document = q.queue[cur]
        if document[1] > max_priority:
            max_priority = document[1]
            max_pos = cur

    return [document_list[max_pos], document_list[max_pos+1:] + document_list[:max_pos]]


for _ in range(int(stdin.readline())):
    N, M = map(int, stdin.readline().split())
    priority_list = stdin.readline().split()
    document_list = []
    print_count = 1

    for index, num in enumerate(priority_list):
        document_list.append((index, int(num)))

    while True:
        printed_document, next_document_list = next_print(document_list)

        if printed_document[0] == M:
            print(print_count)
            break

        if len(next_document_list) == 0:
            break

        print_count += 1
        document_list = next_document_list
