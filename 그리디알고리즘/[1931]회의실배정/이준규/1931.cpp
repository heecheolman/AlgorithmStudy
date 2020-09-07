#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }

    return a.second < b.second ;
}


int main(){
    int n, count = 0, a, b;
    vector<pair<int, int>> v;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a >> b;

        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end(), compare);

    int t = 0;

    for(int i = 0; i < n; i++){
        if(v[i].first >= t){
            count++;
            t = v[i].second;
        }
    }

    cout << count;
}
