# 스택(10828) 풀이

## 접근 방식 
> `Stack`이라는 `class`를 만들었고, `Stack` 인스턴스를 통해 문제에 제시된 조건에 충족하는 스택 객체를 만들어냈다.<br>
> `Stack` 내부적으로 스택의 모양은 배열로 구성하였다. <br>
> 넣을때는 순차적으로 배열에 넣고, 꺼낼 때는 배열의 끝 부터 꺼냈다.


아래는 만들어본 `Stack`클래스이다.
```java
class Stack {
    int[] arr;
    int size=0;

    public Stack (int[] arr) {
        this.arr = arr;
    }

    void push(int num) {
        arr[size] = num;
        size++;
    }

    int pop() {
        if (size == 0) {
            return -1;
        }
        size--;
        int n = arr[size];
        return n;
    }

    int size() {
        return size;
    }

    int empty() {
        if (size == 0) {
            return 1;
        }
        return 0;
    }

    int top() {
        if (size == 0) {
            return -1;
        }
        return arr[size-1];
    }
}
```