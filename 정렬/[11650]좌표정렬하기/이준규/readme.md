# 좌표정렬하기
***
pair < int, int> 방식의 배열을 선언해줍니다
***
### sort 함수

sort 함수 사용법에 대해 찾아봤는데 세 번째 인자를 사용하면 다양하게 정렬을 활용할 수 있다.

> sort(xy, xy + n, compare);

첫 번째 인자부터 두 번째 인자 까지 정렬을 해주는 방식인데
세 번째 compare 부분은 bool 함수로써 이름과 정렬과정을 직접 만들 수 있다

```cpp
bool compare (pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    
    return a.first < b.first;
}
```

나 같은 경우는 bool 함수 이름을 compare로 정했다

오름차순을 원할 경우 오른쪽의 값이 왼쪽 보다 커야하는 경우를 true로 반환해주면 된다. 즉, 자기가 원하는 정렬방식을 true로써 반환 하면 그대로 정렬됨

***

위의 설명을 통해 내림차순으로 정렬을 하고 싶을 경우
> a.first > b.first
x좌표가 같을 경우 y에 대해 내림차순이나 오름차순을 다르게 return할 수 있다

이를 이용해서 좌표정렬하기2 문제를 손쉽게 해결가능

***

물론 좌표정렬하기 ,  좌표정렬하기 2의 문제들을
import 하지않고 직접 선택정렬로 구현해봤는데
시간초과가 나온다 시간이 더 적게 드는 정렬법들로 구현하면 통과하겠지만 
다음에 해볼것임

```cpp
#include<iostream>

using namespace std;

#define endl "\n"

int main()
{
    int n, x, y, min;
    
    cin >> n;
    
    pair<int, int> xy[n], temp;
    
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        xy[i] = make_pair(x, y);
    }
    
    
    for(int i = 0; i < n; i++){
        min = i;
        
        for(int j = i + 1; j < n; j++){
            if(xy[j].first == xy[min].first){
                if(xy[j].second < xy[min].second){
                    min = j;
                }
            }else if(xy[j].first < xy[min].first){
                min = j;
            }
        }
        
        temp = xy[i];
        xy[i] = xy[min];
        xy[min] = temp;
    }
    
    for(int i = 0; i < n; i++){
        cout << xy[i].first << " " << xy[i].second << endl;
    }
}
```
