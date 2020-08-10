# import sys
#
# N = int(sys.stdin.readline())
# treeDic = {}
#
# for i in range(N-1):
#     inputArr = sys.stdin.readline().split(' ')
#     key = int(inputArr[0])
#     value = int(inputArr[1])
#     # key 에 존재하는지 확인
#     if value in treeDic:
#         key, value = value, key
#     else:
#         # value list에 존재하는지 확인
#         for valueArr in treeDic.values():
#             if value in valueArr:
#                 key, value = value, key
#
#     if key not in treeDic:
#         treeDic[key] = []
#     valueArr = [value]
#     treeDic[key] = treeDic[key] + valueArr
#
# for i in range(N-1):
#     for key, values in treeDic.items():
#         if i+2 in values:
#             sys.stdout.write(str(key) + '\n')
#             values.remove(i+2)
#             break

import sys
sys.setrecursionlimit(10**9)

N = int(sys.stdin.readline())
treeDic = {1: 0}
tempList = []

for i in range(N-1):
    inputArr = sys.stdin.readline().split(' ')
    key = int(inputArr[0])
    value = int(inputArr[1])
    # treeDic에 key가 존재하는지 확인
    keyNotIn = key not in treeDic
    valueNotIn = value not in treeDic
    if keyNotIn and valueNotIn:
        tempList.append([key, value])
    elif keyNotIn:
        treeDic[key] = value
    elif valueNotIn:
        treeDic[value] = key

while len(tempList) != 0:
    number = -1
    for (key, value) in tempList:
        number = number + 1
        keyNotIn = key not in treeDic
        valueNotIn = value not in treeDic
        if keyNotIn:
            treeDic[key] = value
            del tempList[number]
        elif valueNotIn:
            treeDic[value] = key
            del tempList[number]


for i in range(2, N+1):
    sys.stdout.write(str(treeDic[i]) + '\n')


# 코드 3
#
# import sys
#
# N = int(input())
# node_graph = [[] for _ in range(N + 1)]
# parent = [[] for _ in range(N + 1)]
#
# # 트리를 그래프 형태로 생성
# for _ in range(N - 1):
#     i, j = map(int, sys.stdin.readline().split())
#     node_graph[i].append(j)
#     node_graph[j].append(i)
#
# print(node_graph)
#
#
# def dfs(start):
#     stack = [start]
#     while stack:
#         node = stack.pop()
#         for i in node_graph[node]:
#             parent[i].append(node)
#             stack.append(i)
#             node_graph[i].remove(node)
#     return parent
#
#
# for i in list(dfs(1))[2:]:
#     print(i[0])
