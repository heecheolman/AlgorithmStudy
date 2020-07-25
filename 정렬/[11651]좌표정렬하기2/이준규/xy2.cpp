#include<iostream>
#include<algorithm>

using namespace std;

#define endl "\n"

bool compare (pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    
    return a.second < b.second;
}


int main()
{
    int n, x, y;
    
    cin >> n;
    
    pair<int, int> xy[n];
    
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        xy[i] = make_pair(x, y);
    }
    
    sort(xy, xy + n, compare);
    
    for(int i = 0; i < n; i++){
        cout << xy[i].first << " " << xy[i].second << endl;
    }
}
