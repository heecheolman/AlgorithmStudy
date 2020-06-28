## 풀이

N 이라는 숫자가 들어올 때 1 ~ N 까지의 카드번호가 카드뭉치로 구성됩니다. 제일 마지막에 남게 되는 카드번호를 구하는 문제인데 작은문제들로 나눠봅니다.

1. 카드뭉치의 가장 위 카드를 버린다 → deQueue
2. 카드뭉치의 가장 위카드를 가장 아래로 넣는다. → deQueue 한 데이터를 enQueue
3. 1 번과 2번을 카드뭉치가 1장 남을때까지 반복

1 번과 2번이 반복적인 로직이여서 재귀함수로 구현을 했습니다. 아래는 의사코드입니다.

```jsx
getCard(deck) {
	if (deck.cards.length == 1) 
		return 카드숫자
	deck.deQueue();
	deck.enQueue(deck.deQueue());
	getCard(deck.cards)
}
```

하지만 입력되는 N 의 수의 크기가 커서 함수호출스택이 가득차 에러를 뱉게되어 while 문으로 변경해 풀었습니다.
