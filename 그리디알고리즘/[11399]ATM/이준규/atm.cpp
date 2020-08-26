#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    int n, time = 0;

    cin >> n;

    int atm[n];

    for(int i = 0; i < n; i++){
        cin >> atm[i];
    }

    sort(atm, atm + n);

    for(int i = n - 1; i >= 0 ; i--){ // 중복누적되면서 배열의 합을 구할 다른 방법도 많을 듯
        for(int j = 0; j <= i; j++){
            time += atm[j];
        }
    }

    cout << time;

}

