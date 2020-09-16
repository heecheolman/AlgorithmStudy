#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[101];
bool visited[101] = {false};

void dfs(int a){
    visited[a] = true;

    for(int i = 0; i < tree[a].size(); i++){
        if(!visited[tree[a][i]]){
            dfs(tree[a][i]);
        }
    }
}

int main(){

int n, edge, a, b;

cin >> n;
cin >> edge;

for(int i = 0; i < edge; i++){
    cin >> a >> b;

    tree[a].push_back(b);
    tree[b].push_back(a);
}

dfs(1);
int count = 0;

for(int i = 2; i <= 100; i++){
    if(visited[i] == true)
        count++;
}


cout << count;
}
