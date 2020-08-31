#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int N;
    cin >> N;

    vector<int> v;
    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int min = 0;
    for (int i = 0; i < v.size(); i++) {
        min = min + (v[i] * N);
        N--;
    }
    cout << min;
}