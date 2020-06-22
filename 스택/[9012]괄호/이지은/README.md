# 괄호(9012) 풀이

## 접근 방식 
> 시작괄호와 끝괄호의 짝이 맞아야 한다.<br>
> 스택은 짝을 맞추기 위해 사용했다.


문제 [[10828]스택](../../[10828]스택/README.md)에서 [내가 작성한 Stack 클래스](../../[10828]스택/이지은/n10828_2.java)를 활용하였다.

1. 스택에는 시작 괄호를 담고, 끝 괄호를 만나면 시작괄호를 스택에서 꺼낸다.
2. 과정 중간에 끝괄호를 만났는데 스택이 비었다면, 짝을 맞출 수 없는 문자열 이기 때문에 과정을 종료해주었다.
3. 모든 과정이 끝나고 스택에 남아있는게 있다면 이 또한 짝을 맞출 수 없는 문자열이 된다.


다음의 문자열로 예시를 만들어 보겠다.
```
(((()())()
```

1. (
    - 시작 괄호다. 스택에 넣어준다. (**push()**)
    - 현재스택 [<span style="color: salmon"> ( </span>]
1. (
    - 시작 괄호다. 스택에 넣어준다.(**push()**)
    - 현재 스택 [<span style="color: salmon"> ( ( </span>]
1. (
    - 상동 / 현재 스택 [<span style="color: salmon"> ( ( ( </span>]
1. (
    - 상동 / 현재 스택 [<span style="color: salmon"> ( ( ( ( </span>]
1. )
    - 끝 괄호다. 스택의 끝 값을 본다.(**top()**)
        - 스택이 비었는지 확인. 안비었으니 꺼낸다.(**pop()**)
    - 현재 스택 [<span style="color: salmon"> ( ( ( </span>]
1. (
    - 시작 괄호다. 스택에 넣어준다. (**push()**)
    - 현재스택 [<span style="color: salmon"> ( ( ( ( </span>]
1. )
    - 끝 괄호다. 스택의 끝 값을 본다.(**top()**)
        - 스택이 비었는지 확인. 안비었으니 꺼낸다.(**pop()**)
    - 현재 스택 [<span style="color: salmon"> ( ( ( </span>]
1. )
    - 끝 괄호다. 스택의 끝 값을 본다.(**top()**)
        - 스택이 비었는지 확인. 안비었으니 꺼낸다.(**pop()**)
    - 현재 스택 [<span style="color: salmon"> ( ( </span>]
1. (
    - 시작 괄호다. 스택에 넣어준다. (**push()**)
    - 현재스택 [<span style="color: salmon"> ( ( ( </span>]
1. )
    - 끝 괄호다. 스택의 끝 값을 본다.(**top()**)
        - 스택이 비었는지 확인. 안비었으니 꺼낸다.(**pop()**)
    - 현재 스택 [<span style="color: salmon"> ( ( </span>]


모든 과정이 끝나고 스택에 괄호가 남아있으므로, VPS가 될 수 없는 문자열이다.

과정 중에 끝 괄호가 빈 스택을 만나면 과정을 종료한다.
<br>예를들어 다음과 같은 문자열이 있으면,

> ()())(())

다섯번째 괄호에서 빈 문자열을 마주치게 된다.

때문에 뒤의 괄호는 확인할 필요 없이 로직을 종료해주어도 된다.


## 주요 코드

```java
// 올바른 괄호 문자열인지 판단하는 메서드
    public static boolean isVps(String text) {
        int j = 0;
        boolean isVps = true;
        stack = new Stack(new char[text.length()]);

        while(isVps && text.length() > j) {
            if (text.charAt(j) == '(') {
                stack.push(text.charAt(j));
            } else { // = ")"
                if (stack.top() == '(') {
                    stack.pop();
                } else {
                    isVps = false;
                    break;
                }
            }
            j++;
        }

        if (stack.size > 0) {
            isVps = false;
        }

        return isVps;
    }
```
