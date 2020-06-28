## 풀이

원형큐(Circular Queue)의 응용문제라 생각했고 작은 문제들로 나누어 봤습니다.

1. N명의 사람이 원형 큐를 이룬다.
2. 원형큐를 순회하며 K번째가 되었을 때 K번째 사람을 제외시킨다.
3. 제외시킨 위치를 기준으로 새로운 원형 큐를 생성한다.

새로 만들 원형 큐가 없을 때까지 1 ~ 3번을 반복합니다.

원형 큐를 순회하며 count 가 at 번째 사람이 될 때까지 반복하고(2번), 해당 위치를 기준으로 나머지 요소들로 이루어진 새로운 원형 큐를 만들어 줍니다. 제외된 사람과 다음 원형 큐를 반환하고 이는 다시 1번의 반복으로 돌아갑니다.

```python
def get_next_people(people, at):
    circular_queue = CircularQueue(people)
    count = 1

		# 2번
    while count != at:
        circular_queue.next()
        count += 1
		# 3번
    next_queue = circular_queue.queue[circular_queue.cur+1:] + circular_queue.queue[:circular_queue.cur]

    return [circular_queue.get_cur_item(), next_queue]
```