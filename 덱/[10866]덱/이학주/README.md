# [덱 (10866)](https://www.acmicpc.net/problem/10866)

## 풀이
덱은 양옆에서 넣고 빼고가 가능하다. 이 점을 생각하여 코드를 구현해봤다.

나는 가운데를 기준으로 양쪽으로 인덱스를 참조하여 push 혹은 pop을 가능하도록 생각했다.
그렇기때문에 처음 입력받는 명령의 수인, 변수 N을 기준으로 생각했다.

만약 N이 10이면서 push_front만 10개로 이루어져있다는 경우를 생각하여,
가운데를 기준으로 한쪽에서만 push가 이루어지는 경우를 생각하여 범위를 지정해주었다.

처음 입력받는 수 N의 범위는 1 <= N <= 10,000이다.
그렇기때문에, 덱의 크기는 20,000으로 지정해두었다.

<pre><code>

Deque()
{
    cin >> N;
    start = N - 1;
    end = N;
}

int data[20000];

</code></pre>

push_front -> start로 인덱스 접근
push_back -> end로 인덱스 접근

start와 end라는 변수를 통해서 처음점과 끝점으로 인덱스를 접근하도록 하였다.

<pre><code>

    void push_front(int value)
    {
        data[start] = value;
        start--;
    }

    void push_back(int value){
        data[end] = value;
        end++;
    }

    int pop_front(){

        if( empty() ){
            return -1;
        }
        else{
            start++;
            return data[start];
            data[start] = 0;
        }
    }

    int pop_back(){

        if( empty() ){
            return -1;
        }
        else{
            end--;
            return data[end];
            data[end] = 0;
        }
    }

    int front(){
        if( empty() ){
            return -1;
        }
        else{
            return data[start + 1];
        }
    }

    int back(){
        if( empty() ){
            return -1;
        }
        else{
            return data[end - 1];
        }
    }

</code></pre>
