#include <iostream>
using namespace std;

int main(){
    int a, h, w, n;
    cin>>a;
    int room[a];
    for(int i = 0 ; i<a; i++){
        cin>>h>>w>>n;
        if(n%h==0)room[i]= h*100 + (n/h);
        else room[i] = (n%h)*100 + (n/h +1);
    }
    for(int i=0;i<a;i++)cout<<room[i]<<endl;
}


/*
 a 번 만큼 계산을 반복해야하는 것을 a 크기의 배열을 만들어서 결과를 넣어놓고 한번에 출력
 h w n 을 입력받지만 w는 사용안해도됨
 방의 층수는 n을 h 로 나눈 나머지임
 근데 꼭대기층( n 이 h의 배수)일 경우 나머지가 0이라서 층수가 0이됨
 그래서 두 경우로 나눔
 호수는 한자리일 수도 있고 두자리일 수도 있는데 한자리일 경우 0n 이되어야하기때문에
 층수에 100을 곱한것에 호수를 더하면 정수형으로 호수를 나타낼수 있음
 꼭대기층일 경우엔 호수가 n을 h로 나눈 몫이됨
 꼭대기층이 아니면 몫에 1을 더해야함
 */
