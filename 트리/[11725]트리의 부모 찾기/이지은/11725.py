
# 코드 3

import sys

N = int(input())
node_graph = [[] for _ in range(N + 1)]
parent = [[] for _ in range(N + 1)]

# 트리를 그래프 형태로 생성
for _ in range(N - 1):
    i, j = map(int, sys.stdin.readline().split())
    node_graph[i].append(j)
    node_graph[j].append(i)

print(node_graph)


def find_parent(start):
    stack = [start]
    while stack:
        node = stack.pop()
        for i in node_graph[node]:
            parent[i].append(node)
            stack.append(i)
            node_graph[i].remove(node)
    return parent


for i in list(find_parent(1))[2:]:
    print(i[0])
