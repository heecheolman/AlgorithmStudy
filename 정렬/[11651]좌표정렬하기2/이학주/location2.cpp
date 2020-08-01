#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main () {
    vector < pair <int, int> > v;

    int N, a, b;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back(pair<int, int>(b, a));
    }
    sort(v.begin(), v.end());

    vector < pair <int, int> > ::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++) {
        cout << iter->second << " " << iter->first << "\n";
    }
}