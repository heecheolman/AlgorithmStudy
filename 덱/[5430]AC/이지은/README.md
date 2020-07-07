# AC(5430) 풀이

## 접근 방식 
> R 함수 시, 실제 배열을 뒤집지 않고 배열의 뒤에서 D하도록 처리해주는 것이 포인트다.<br>
> 배열은 앞과 뒤로 자유롭게 삭제할 수 있는 linkedList로 사용하였다.

### 로직

- `T = 테스트 케이스`만큼 반복한다.
- `함수 문자열` -> `배열에 들어갈 수` -> `수 만큼의 배열`을 차례대로 입력받는다.

```java
    for (int i=1; i <= T; i++) {
        list = new LinkedList<>();
        char[] function = reader.readLine().toCharArray(); // 함수
        int n = Integer.parseInt(reader.readLine()); // 배열에 들어갈 수
        // 배열은 문자열로 입력받아서 불필요한 문자열을 제거하여 split해주었다.
        String[] arr = reader.readLine()
                .replace("[", "")
                .replace("]","")
                .split(",");
        ...
    }
```

- 에러인 경우를 체크해준다.
	-  `배열에 들어갈 수`(n) 보다 `D`의 개수가 큰 경우

```java
	if (isError(function, n)) {
        writer.write("error" + "\n");
        continue;
    }
```

```java
    private static boolean isError(char[] p, int n) {
        int count = 0;

        for (char s : p) {
            if (s == 'D') {
                count++;
            }
        }

        return n < count;
    }
```

- 빈배열의 경우를 체크해준다.
	- 위의 `에러인 경우를 체크해준다.`와 순서가 바뀌면 안된다.
	- _빈배열이면서 `D`를 시도하는 입력의 경우 `error`를 내주어야 하는데 순서가 바뀌면 빈배열을 출력하기 때문에 잘못된 로직이다._

```java
    if (arr[0].equals("")) {
        writer.write(formatResult(list) + "\n");
        continue;
    }
```	

- 초기 리스트(LinkedList)를 세팅한다.

```java
    for (String s : arr) {
        list.offer(Integer.parseInt(s));
    }
```

- `함수 문자열`을 순차적으로 실행한다.
	- 이 때 `isReverse `으로 `R`함수가 실행됐다는 것을 체크해준다.
	- `isReverse == true` 이면, `list.pollLast();`
	- `isReverse == false` 이면, `list.poll();`
	
```
    boolean isReverse = false;
    for (char c : function) {
        if (c == 'R') {
            isReverse = !isReverse;
        } else if (c == 'D') {
            if (isReverse) {
                list.pollLast();
            } else {
                list.poll();
            }
        }
    }
```

- 마지막엔 `isReverse` 인 경우, `배열 뒤집기`를 실행한다.

```java
    if (isReverse) {
        Collections.reverse(list);
    }
```
