# 큐2 (18258) 풀이

## 접근
> 가장 먼저 떠올랐던 방법은 `linkedList`다.  `linkedList`를 import해서 사용하면 `queue`를 쉽게(?) 만들어 낼 수 있다.<br>
> 근데 그건 이미 만들어진걸 가져와서 쓰는거잖아....(동공지진)<br><br>
> 접근이 잘못되었기에 자연스럽게 `linkedList`를 뜯어보게 되었다.(?)<br>
>
> ```java
> 
> public class LinkedList<E>
>     extends AbstractSequentialList<E>
>     implements List<E>, Deque<E>, Cloneable, java.> io.Serializable
> {
>          ...
> }
> ```
> `linkedList`는 `list`와 `Deque` 인터페이스를 구현(implements) 하고있다.<br>
>  `Deque`...? `Deque`을 쫒아가보았다.<br>
> ```java
> 
> public interface Deque<E> extends Queue<E> {
>          ...
> }
> ```
> 하마터면 `queue`를 구현하고있는 `linkedList`를 양아치처럼 가져와 쓸 뻔 했다.ㅎㅎ!!!<br><br>
>
> 자연스럽게 `linkedList`코드를 보게되었는데 `linkedList`답게 `node`를 사용해 구현되어 있었다.
> 이를 참고해서 **큐**(`queue`) 를 구현해보았다... (대충 훔쳐보고 만들었다는 말)
<br>

## 구현

먼저 노드 class를 만들었다. 

```java
    static class Node {
        Node prevN; // 앞 노드
        int num; // 숫자 저장.
        Node nextN; // 뒷 노드

        Node (Node prevN, int num, Node nextN) {
            this.prevN = prevN;
            this.num = num;
            this.nextN = nextN;
        }
    }
```

큐 class에 node class를 포함시켜 구현하였다.<br>
큐 class 를 만들었다.

```java
class Queue {
    int size = 0;
    Node firstN; // 큐의 첫번째 노드
    Node lastN; // 큐의 마지막 노드
}
```
linkedList처럼 각 노드들을 이어주고, 선입선출 규칙을 따르도록 method를구현해주었다.

### push
```java
    void push(int n) {
        if (size == 0) {
            this.firstN = new Node(null, n, null);
            this.lastN = this.firstN;
        } else {
            Node newN = new Node(lastN, n, null);
            this.lastN.nextN = newN;
            this.lastN = newN;
        }
        this.size ++;
    }
```

### pop ( 코드 정리는 시간부족으로 못함.... )
```java
    int pop() {
        if (size == 0) {
            return -1;
        }

        this.size--;
        int n = this.firstN.num;
        Node newFirstN = this.firstN.nextN;

        if (newFirstN == null) {
            return n;
        }
        
        newFirstN.prevN = null; // 바로 뒷 노드에서 맨 앞 노드로의 연결 제거
        this.firstN.nextN = null; // 맨 앞노드에서 뒷 노드로의 연결 제거
        this.firstN = newFirstN;

        return n;
    }
```

### 그 외 (귀찮으니.. )
```java
    int size() {
        return this.size;
    }
    int empty() {
        return this.size > 0 ? 0 : 1;
    }
    int front() {
        if (size == 0) {
            return -1;
        }
        return this.firstN.num;
    }
    int back() {
        if (size == 0) {
            return -1;
        }
        return this.lastN.num;
    }
```
