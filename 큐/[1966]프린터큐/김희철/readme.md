## 풀이

큐(문서 전체)에 대해 우선순위가 가장 높은 요소를 먼저 출력한다는게 핵심입니다.

1. 큐를 전체 순회하여 가장 높은 우선순위를 가진 위치가 출력 대상
2. 출력 대상과 출력 대상을 기준으로 왼쪽에 놓여진 요소들을 가장 뒤로 위치시켜 1번에 적용할 새로운 큐를 반환
3. 출력 대상이 원하는 출력 순서인지 판단후 결과값 구하기
4. 출력할 것이 없을 때가지 반복

```python
def next_print(document_list):
		# 문서 리스트를 큐로 초기화
    q = Queue(document_list)

		# 높은 우선순위 값을 찾기 위한 초기작업
    max_priority = 0
    max_pos = 0

		# 큐 전체 순회
    for cur in range(q.head, q.tail + 1):
        document = q.queue[cur]
				# 가장 높은 우선순위의 문서 저장
        if document[1] > max_priority:
            max_priority = document[1]
            max_pos = cur

		# 반환 첫번째: 출력대상
		# 반환 두번째: 다음 순회할 문서리스트
    return [document_list[max_pos], document_list[max_pos+1:] + document_list[:max_pos]]
```