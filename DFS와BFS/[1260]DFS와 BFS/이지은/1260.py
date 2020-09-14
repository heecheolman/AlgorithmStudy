

arr = input().split()

N = int(arr[0])
M = int(arr[1])
V = int(arr[2])

bfsGraph = [[] for _ in range(M)]
dfsGraph = []

stack = []
queue = []

for i in range(M):
    nodes = input().split()
    print(str(nodes))
    bfsGraph[int(nodes[0]) - 1].append(int(nodes[1]))
    bfsGraph[int(nodes[1]) - 1].append(int(nodes[0]))

for arr in dfsGraph:
    arr.sort(reverse=True)

for arr in bfsGraph:
    arr.sort()


# 깊이 탐색
def dfs(startNode):
    answer = ''
    stack.append(startNode)

    while stack:
        currentNode = stack.pop()
        if currentNode in stack:
            stack.remove(currentNode)
        answer = answer + ' ' + str(currentNode)
        for linkedNode in dfsGraph[currentNode - 1]:
            a = linkedNode - 1
            dfsGraph[a].remove(currentNode)
            stack.append(linkedNode)

    print(answer.strip())


# 너비 탐색
def bfs(startNode):
    answer = ''
    queue.append(startNode)
    while queue:
        currentNode = queue[0]
        queue.remove(currentNode)
        answer = answer + ' ' + str(currentNode)
        for linkedNode in bfsGraph[currentNode - 1]:
            a = linkedNode - 1
            bfsGraph[a].remove(currentNode)
            queue.append(linkedNode)

    print(answer.strip())


dfs(V)
bfs(V)
