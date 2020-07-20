
# 병합정렬

### 시간 복잡도 O(n log n)

***

1. (main) 배열에 mergesort 함수를 실행한다. mergesort(arr, start, end)

2. (mergesort) 받은 배열을 반으로 나눠서 각각 재귀적으로 mergesort 한다.

```cpp
leftarr = mergesort(arr, start, (start + end) / 2 ) ;
rightarr = mergesort(arr, (start + end) / 2 + 1, end) ;
```
 
3. 받은 배열의 크기가 1이면 그대로 리턴한다.

4. (mergesort) 각각 정렬된 왼쪽과 오른쪽 배열이 있다.

5. (mergesort) 양쪽의 배열에는 각각 맨 앞칸을 가리키는 인덱스가 있다.

6. (mergesort) 인덱스를 이용해서 각 배열의 인덱스가 가리키는 수를 비교해주고 더 작은것을 리턴할 배열에 append 

7. (mergesort) 전에 비교했던 수중에 더 컸던 수의 인덱스를 그대로 두고 작아서 append 했던 인덱스를 +1 한다.

8. 6~7 과정을 반복한다. (양쪽 중 한 배열의 인덱스의 맨 마지막칸 수까지 append 할 때까지)

9. 양쪽중의 한 배열의 원소를 모두 리턴할 배열에 append 했으면 나머지 하나의 배열은 사용되지 않은 원소가 남아있다. (이 원소들은 반대 배열의 모든 원소들보다 큰 숫자이다.)

10. 그 배열의 남은 수를 차례로 리턴할 배열에 append 한다.

***

```cpp
#include<iostream>
#include<vector>

using namespace std;

#define endl "\n"

vector<int> MergeSort(vector<int> array, int begin, int end)
{
  if(array.size() <= 1)
  {
    return array;
  }
  vector<int> left(array.begin()+begin, array.begin()+(begin+end)/2+1);
  vector<int> right(array.begin()+(begin+end)/2 + 1, array.end());

  left = MergeSort(left, 0, left.size()-1);
  right = MergeSort(right, 0, right.size()-1);

  vector<int> ret;

  int left_size = left.size();
  int right_size = right.size();
  int left_index = 0, right_index = 0;


  while(left_index < left_size && right_index < right_size)
  {
    int left_elem = left[left_index];
    int right_elem = right[right_index];

    if(left_elem == right_elem)
    {
      ret.push_back(right_elem);
      ++right_index;
    }
    else if(left_elem > right_elem)
    {
      ret.push_back(right_elem);
      ++right_index;
    }
    else if(left_elem < right_elem)
    {
      ret.push_back(left_elem);
      ++left_index;
    }
  }

  if(left_index == left_size)
  {
    while(right_index < right_size)
    {
      ret.push_back(right[right_index++]);
    }
  }
  else if(right_index == right_size)
  {
    while(left_index < left_size)
    {
      ret.push_back(left[left_index++]);
    }
  }

  return ret;
}

vector<int> array;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;

  for(int i=0;i<N;i++){
    int temp;
    cin >> temp;
    array.push_back(temp);
  }

  vector<int> sorted_array = MergeSort(array, 0, array.size()-1);

    for(int i = 0; i < N; i++){
        cout<<num<<" ";
    }
    cout<<endl;

}
```

