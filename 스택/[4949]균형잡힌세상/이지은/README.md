# 균형잡힌세상(4949) 풀이

## 접근 방식 
> 시작 괄호만 스택에 넣는다.<br>
> 올바른 끝 괄호를 만나면 pop해주었다.<br>
> 마지막에 스택이 비었으면, 균형 잡힌 괄호이다.

다음 순서대로 구현하였다.

1. 입력문을 종료하는 '`.`'을 입력할 때 까지 반복한다.
1. 입력 문장의 문자 하나하나에 접근한다.
3. 문자의 타입에 따라 반복문을 종료하거나, 조건문을 실행한다.
    1. 괄호가 아니면, _다음 문자로 넘어간다_.
    1. 열림괄호('`(`', '`[`')면, 스택에 push하고 _다음 문자로 넘어간다_.
    1. 그 외의 경우는 닫힘 괄호 밖에 없다. 이 때는 두가지 경우가 있다.
        1. 불균형 괄호 : 스택이 비었거나, 짝이 맞지 않는 경우.
        2. 균형 괄호 : 1번이 아닌 경우 

### 1. 입력에 대한 반복문 및 입력 종료
while 문을 사용하여 `.`이 입력될 때 까지 반복문을 돌렸다.<br>

```java
while(true) {
    stack.removeAllElements(); // 반복문 초기에 스택 초기화.
    String sentence = reader.readLine();
    if (sentence.equals(".")) {
        break;
    }
    ..
    ..
}
```
### 2. 문자열의 문자 하나하나에 접근
그 다음으로 문장을 char 단위로 나누는 작업이 필요하다.<br>
char 단위로 모든 문자를 확인해줘야 하기 때문에 for문을 사용했는데, 가능한 방법은 두 가지다.

방법 1.
```java
for (int i = 0; i < sentence.length(); i++) {
    char c = sentence.charAt(i);
    ..
    ..
}
```
방법 2.
```java
for (char c : sentence.toCharArray()) {
    ..
    ..
}
```

가독성을 위해(더 발전된 코드를 위해..) 향상된 for문인 `방법2`를 사용했다.

### 3. 문자의 타입에 따라 조건 실행 (괄호아님 / 열림괄호 / 닫힘괄호)

문자 타입을 구분해주는 조건은 미리 선언해두었다. (가독성을 위해..)

```java
boolean isNotBlanck = c != '(' &&  c != ')' && c != '[' && c != ']'; // 괄호가 아닌 경우
boolean isStart = c == '(' || c == '['; // 열림 괄호인지
boolean isNotCouple = (stack.peek() != '(' && c == ')') || (stack.peek() != '[' && c == ']'); // 짝이 맞는지
```

그리고 조건에 따라 케이스를 구분해주어야 했는데, 가장 처음에 떠오른 코드는 대충 다음과 비슷하다.

```java
if (isStart) { // 열림괄호
    stack.push(c);
} else { // 닫힘괄호
    if (stack.empty() || isNotCouple) {
        stack.push('('); // * 방어코드 *
    } else {
        stack.pop();
    }
}
```

근데 for문 안에 2depth가 들어가는 if문이 있는것이 영 마음에 들지 않았다... (for문, while문 까지 고려하면 총 4depth...)

그래서 `continue`와 `break`를 사용해 if문의 depth를 줄여보았다.

```java

if (isNotBlanck) { // 괄호 아님
    continue;
}
if (isStart) { // 열림괄호
    stack.push(c);
    continue;
}
// 닫힘괄호
if (stack.empty() || isNotCouple) {
    stack.push('('); // * 방어코드 *
    break;
}
stack.pop(); // 짝이 맞으면 pop
```


for문이 종료되고 스택이 비었으면, 균형잡힌 문장이다.

```java
System.out.println(stack.empty() ? "yes" : "no");
```