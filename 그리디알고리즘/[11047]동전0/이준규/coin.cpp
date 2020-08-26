#include <iostream>
#include <vector>

using namespace std;


int main(){
    int n, won, coin, count = 0;
    vector<int> v;

    cin >> n >> won;

    for(int i = 0; i < n; i++){ // 동전의 가치가 맞춰야할 금액보다 크면 1개도 쓸 수 없어서 어차피 무쓸모(메모리 아끼기)
        cin >> coin;

        if(coin <= won)
            v.push_back(coin);
    }

    for(int i = v.size() - 1; i >= 0; i--){ // 동전으로 나눈몫이 0이면 그 동전은 못쓰고 큰 동전부터 몫을 카운팅하고 금액은 그 나머지로 바꾸기
        if(won / v[i] != 0){                //위 조건때문에 사실 입력을 다 받아도 상관은 없다
            count += won / v[i];            //하지만 금액이 나머지값으로 업뎃되게 때문에 이 조건은 필수
            won = won % v[i];
        }
    }

    cout << count;


}
