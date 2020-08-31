#include <iostream>
#include <vector>

using namespace std;

int main () {
    int N, K;
    cin >> N >> K;

    int a = 0;
    vector<int> v;
    for (int j = 0; j < N; j++) {
        cin >> a;
        v.push_back(a);
    }
    
    int count = 0;
    int temp = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (K >= v[i]) {
            temp = K / v[i];
		    count = count + temp;
		    K = K % v[i];
        }
    }

    cout << count;
}
