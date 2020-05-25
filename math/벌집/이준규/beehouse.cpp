#include <iostream>
using namespace std;

int main(){
    int n, count=1;
    cin>>n;
    for(int s = 1 ; s<n ; count++) s += 6 * count;
    cout<<count;
}

/*
 count는 가운데서부터세는 칸 수
 숫자 1까지는 1칸, 7까지는 2칸, 19까지는 3칸 ...
 칸 수는 6 * 칸 수  만큼 늘어남
 입력 받은 수가 1 일때는 칸수가 1인 경우를 빼두고
 총 칸수 s 에 6 * 칸수 를 입력받은수를 넘지 않게 루프를돌린다
 */
