#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int>> tree[100001];
int r = 0 ,far = 0;
bool check[100001];

void dfs(int a, int d){
    if(check[a]){
        return;
    }

    check[a] = true;

    if(d > r){
        r = d;
        far = a;
    }

    for(int i = 0; i < tree[a].size(); i++){
        dfs(tree[a][i].first, d + tree[a][i].second);
    }
}

int main(){
    int n, a, b, c; 

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a;
        while(true){ 
            cin >> b;
            if(b == -1) break;
            cin >> c;

            tree[a].push_back(make_pair(b, c));
        }
    }
    
    memset(check, false, sizeof(check));
    dfs(1, r);

    r = 0;

    memset(check, false, sizeof(check));
    dfs(far, r);

    cout << r;
}
