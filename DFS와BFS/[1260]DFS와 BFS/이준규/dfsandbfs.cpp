#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> tree[1001];
bool check[1001] = {false};
queue<int> q;

void dfs(int n){
    check[n] = true;

    cout << n << " ";

    for(int i = 0; i < tree[n].size(); i++){
        if(!check[tree[n][i]]){
            dfs(tree[n][i]);
        }
    }

}

void bfs(int n){
    q.push(n);
    check[n] = true;

    while(!q.empty()){
        int x = q.front();
        cout << q.front() << " ";
        q.pop();

        for(int i = 0; i < tree[x].size(); i++){
            if(!check[tree[x][i]]){
                q.push(tree[x][i]);
                check[tree[x][i]] = true;
            }
        }
    }

}

int main(){
    int a, b, c, d, e;

    cin >> a >> b >> c;


    for(int i = 0; i < b; i++){
        cin >> d >> e;

        tree[d].push_back(e);
        tree[e].push_back(d);
    }

    for(int i = 1; i <= a; i++){
        sort(tree[i].begin(), tree[i].end());
    }

    dfs(c);
    memset(check, false, sizeof(check));
    cout << "\n";
    bfs(c);

}
