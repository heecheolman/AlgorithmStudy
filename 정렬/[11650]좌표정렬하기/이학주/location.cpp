#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main () {
    vector < pair <int, int> > v;

    int N, a, b;
    cin >> N;

    while (N--){
        cin >> a >> b;
        v.push_back(pair<int, int>(a, b));
    }
    sort(v.begin(), v.end());

    vector < pair <int, int> > ::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++) {
        cout << iter->first << " " << iter->second << "\n";
    }
}