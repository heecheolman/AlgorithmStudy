# [수 정렬하기2 (2751)](https://www.acmicpc.net/problem/2751)

나는 이 문제를 퀵정렬로 구현해보려고 하였다.
그렇지만 퀵정렬의 개념은 이해하였지만 코드화하는데 어려움을 느꼈다.

피봇을 지정하여 피봇 기준으로 왼쪽은 작은수 오른쪽은 큰수로 정렬하는데 성공했다.
그렇지만 그 다음 재귀적으로 접근할 때, 
재귀를 탈출하는 조건은 배열의 크기가 1일때 인데 인자값을 어떻게 설정할지에 대해서 막혔다.

그래서 병합정렬로 접근해보았지만 마찬가지로 개념은 이해하였지만 코드화하는데 어려웠다.
다른 사람의 코드를 가져와서 봤지만 코드를 이해하기가 어려웠다,,

우선 백준 기준 병합정렬 성공한 코드이다.

```c++
#include<iostream>

using namespace std;

int N, arr[1000001];
int *arr2;

void merge(int left, int right)
{
	int mid = (left + right) / 2;

	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j]) 
			arr2[k++] = arr[i++]; 
		else
			arr2[k++] = arr[j++];
	}

	int tmp = i>mid ? j : i;
	
	while(k<=right) arr2[k++] = arr[tmp++];

	for (int i=left;i<=right;i++) arr[i] = arr2[i];
}

void partition(int left,int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2; 
		partition(left, mid);
		partition(mid + 1, right);
		merge(left, right);
	}
}

int main()
{
	scanf("%d",&N);
	arr2 = new int[N];
	for (int i=0;i<N;i++) scanf("%d",&arr[i]);

	partition(0, N - 1);

	for (int i=0;i<N;i++) printf("%d\n",arr[i]) ;
}
```

다른 건 이해하였는데 merge 함수를 이해하는데 어려웠다.