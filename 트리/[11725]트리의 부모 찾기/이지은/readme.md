# 트리의 부모 찾기 설명

### 접근 방법

- 딕셔너리로 접근했다가 시간초과가 자꾸 발생하고, 그 외의 접근 방법을 발견하지 못했다. 코드 서칭 후 공부하여 문제를 풀었다.
- dfs로 풀었다.


### 코드 설명

- node_graph 배열 생성 : 1부터 N까지의. 노드는 무조건 발생하기 때문에 0~N으로 배열을 초기화 한다.

	 ```py
		node_graph = [[] for _ in range(N + 1)]
	```

- node_graph 배열 값 세팅 : 해당 인덱스는 노드값이다. 해당 노드값과 연결되는 노드(부모 & 자식)를 모두 저장해준다.

	 ```py
	for _ in range(N - 1):
		i, j = map(int, sys.stdin.readline().split())
		node_graph[i].append(j)
		node_graph[j].append(i)
	```
		
-  parent배열 생성 : 1부터 N까지의 부모를 찾아 저장 후 출력해줄 parent 배열을 초기화한다.

	```py
	 parent = [[] for _ in range(N + 1)]
	```
		
- `stack`에 진행 순서별로 노드를 쌓아준다. (초기화 : 1)
	- 예) 
	- stack.pop()하여 1을 꺼낸다 
		- 	자식or부모 : (6, 4)
		-  노드 6 :
			-  노드6의 부모 = 1
			-  노드6에서 1을 제거
			-  stack에 6 추가
		-  노드 4 :
			-  노드4의 부모 = 1
			-  노드4에서 1을 제거
			-  stack에 4 추가
	-  stack.pop()하여 4을 꺼낸다 
		- 	자식or부모 : (2, 7) (앞에서 1은 제거해줌)
		-  노드 2 :
			-  노드2의 부모 = 4
			-  노드2에서 4을 제거
			-  stack에 2 추가
		-  노드 7:
			-  노드7의 부모 = 4
			-  노드7에서 4을 제거
			-  stack에 7 추가
		- (반복)

	```py
	def dfs(start):
	    stack = [start]
	    while stack:
	        node = stack.pop()
	        for i in graph_list[node]:
	            parent[i].append(node)
	            stack.append(i)
	            graph_list[i].remove(node)
	    return parent
	```
	
	
	
	### 기존에 작성한 실패 코드
	
	
	```py
		
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

	```