#include <iostream>
#include <vector>

using namespace std;

    vector<int> tree[100001];
    int result[100001];
    bool par[100001] = {false};

    void parent(int a){
        par[a] = true;

            for(int i = 0; i < tree[a].size(); i++){
                if(!par[tree[a][i]]){
                    result[tree[a][i]] = a;
                  parent(tree[a][i]);
                }
            }
    }

int main(){
    int n, a, b; 

    cin >> n;



    for(int i = 0; i < (n - 1); i++){
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    parent(1);

    for(int i = 2; i <= n; i++){
        cout << result[i] << "\n";
    }
}
