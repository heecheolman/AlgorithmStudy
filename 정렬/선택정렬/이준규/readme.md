# 선택정렬

1. 배열의 크기가 N 이라면 N - 1 회  검사가 진행된다.

2. 배열 첫 째 원소를 선택.

3. 그 뒤의 원소부터 맨 뒤의 원소까지의 범위에서 최소값을 찾는다. 

4. 그 최소값과 첫 째 원소를 swap.

5. 배열 두 번째 원소를 선택하고 3~4번 과정을 진행한다.

6. 5번 과정을 N - 1 번째 원소를 선택할 경우까지 진행한다.

7. 정렬완료.

***

```cpp
for(int i = 0; i < N - 1; i++){
    min = i;
    
    for(int j = i + 1; j < n; j++){
        if(data[j] < data[min])  min = j;
    }
    
    if(i != min){
        swap(data[i], data[min]);
    }
}
```

