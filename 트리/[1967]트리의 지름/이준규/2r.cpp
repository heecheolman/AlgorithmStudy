// 1167의 문제와는 입력받는 방식만 다르게 한다
// 부모와 자식관계를 저장하지만 자식입장에서도 부모와 연결되어있다는 정보를 함께 저장한다

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

    for(int i = 0; i < (n - 1); i++){
        cin >> a >> b >> c;

        tree[a].push_back(make_pair(b, c));
        tree[b].push_back(make_pair(a, c));
    }
    
    memset(check, false, sizeof(check));
    dfs(1, r);

    r = 0;

    memset(check, false, sizeof(check));
    dfs(far, r);


    cout << r;
}
