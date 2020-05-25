#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long a, x, y, b;
    cin>>b;
    long long move[b];
    for(int i = 0 ; i<b; i++){
        cin>>x>>y;
        a = (int)sqrt(y-x);
    
        if(a*a==(y-x)) move[i] = a*2-1;
        else if(a*a<(y-x) && (y-x)<=a*a+a) move[i] = 2*a;
        else if(a*a+a<(y-x) && (y-x)<(a+1)*(a+1)) move[i] = 2*a+1;
   }
    for(int i=0; i<b;i++)cout<<move[i]<<endl;
}

/*
 y와 x의 거리에따른 작동횟수를 1부터 구해봤을 때
 작동횟수가 거리에따라 늘어나는 규칙을 찾으려했는데 못찾음
 그래서 거리(y-x)에 따른 작동횟수를 쭉써서 거리와 횟수의 관계를 일일이 찾으려하다보니
 거리가 제곱수일때는 (ex 9 = 3^2) 제곱근*2 -1 이 작동횟수 라는 걸 확인했고
 그 후로 제곱근칸수 뒤까지는 2*제곱근
 그 뒤로 다음 제곱수 까지는 2*제곱근+1 이길래 3가지 경우로 나눠서 식을 표현했다.
 
 거리.  작동횟수
 1      1
 2      2
 3      3
 4      3
 5      4
 6      4
 7      5
 8      5
 9      5 (여기서의 제곱근 3)
 10     6(여기서부터 3칸동안 2 곱하기 제곱근)
 11     6
 12     6
 13     7(여기서부터 다음 제곱수까지 2곱하기 제곱근 +1)
 14     7
 15     7
 16     7
 */
