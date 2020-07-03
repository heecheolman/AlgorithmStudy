

에러를 출력 해줄지 판별하는 error와
리버스 된 상태인지를 판별하는 r 

두 boolean 변수를 선언 해줘요

함수와 입력받을 size 변수는 입력은 받지만 제 코드에서는 사용하지 않아요

왜냐면 deque에 push 하는 기준은 size의 횟수가 아니라 comma를 발견할 때 이기 때문이에요

```cpp
        for(int j = 0 ; j < sub.size() ; j++){
            if(sub[j] == ','){
                n = atoi(sub.substr(0, j).c_str());
                q.push_back(n);
                sub = sub.substr(j+1);
                j = 0;
            }
            else if(sub[j] == ']'){
                if(j == 0) b = true;
                n = atoi(sub.substr(0, j).c_str());
                q.push_back(n);
                break;
            }
        }
```
처음에 제가 입력을 받아서 push 하는 코드이지만 너무 지저분 하기도 하고
시간초과가 자꾸 나와서 바꿨어요 코드를 많이 바꿔서 이것 때문에 시간초과가 나온지는 모르겠어요

구글링에 c++에서 스플릿하는 다양한 방법을 찾아 보고는 istringstream 을 사용했어요 
문자열을 읽어 들이는 건데 이것을 이용하면 getline을 이용해 스플릿 할 수 있습니다

아 참 콤마를 기준으로 스플릿하기 전에 맨앞 맨뒤의 대괄호를 지우고 sub 스트링에 넣어줄게요

그후 콤마를 기준으로 stringBuffer 변수에 담아서 정수형으로 변환한 뒤 push 해줍니다


***

입력받은 fx 문자열의 길이로 반복문을 사용해서 함수가 차례대로 사용되게 합니다

함수가 D 인데 deque이 비어있으면 에러를 출력해야 하기때문에 error를 true로 바꾸고 반복문을 빠져나와요


R 함수가 들어오면 boolean r 변수를 NOT 해줘서 현재 상태가 거꾸로 읽는 상태인지 아닌지를 가려줘요

실제로 deque를 뒤집지는 않습니다 ! 내 생각엔 계속 시간초과 나온 이유가 이거 때문인거 같아요

```cpp
                for(int k = 0 ; k < q.size() ; k++){
                    reverseQ.push_front(q[k]);
                }
                
                q.clear();
                
                for(int k = 0 ; k < reverseQ.size() ; k++){
                    q.push_back(reverseQ[k]);
                }
                reverseQ.clear();
```

이렇게 deque를 복사해서 뒤집어도 제대로 동작은 합니다

push front 로 복사를 하면 리버스가 되고 push back 으로 복사하면 그대로 복사됩니다


그 외에 D 함수가 들어왔을때, r 의 상태따라 pop을 front 로 할 지 back 으로 할지 나눠줍니다
실제로 deque가 리버스된 상태가 아니기 때문에 리버스된 상태라고 치면 뒤에서 pop을 해야 
리버스된 상태로 pop front 한 동작과 같게돼요

***

그 후 error 변수를 확인해서 에러를 출력해주거나
r 변수의 상태에 따라 output에 뒤에서부터 추가해줄지 앞에서부터 추가해줄지 출력하는 방식을 나눠줍니다

***
어려웠던반례
1
R
0
[]
이런 입력이 들어오면 [] 가 출력돼야하고 에러가 나오면 안됩니다.
(질문검색에서 반례를 찾음)

때문에 출력하는 방식을 하나 더 추가 해줬습니다(q가 비어있을때는 그냥 대괄호를 닫고 출력)
