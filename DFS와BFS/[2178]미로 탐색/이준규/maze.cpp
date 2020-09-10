#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[100][100] = {0};
int edge[100][100] = {0};
bool check[100][100];
int sum = 0;
queue<pair<int, int>> q;
int N, M;

void bfs(int a, int b){
    
    check[a][b] = true;
    edge[a][b] = 1;

    q.push(make_pair(a, b));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;


        q.pop();

        if(map[x + 1][y] == 1 && x + 1 < N + 1){
            
            if(!check[x+1][y]){
                q.push(make_pair(x + 1, y));
                check[x+1][y] = true;
                edge[x+1][y] = edge[x][y] + 1;
            }
        }
        
        if(map[x][y + 1] == 1 && y + 1 < M + 1){
            
            if(!check[x][y+1]) {
                q.push(make_pair(x, y + 1));
                check[x][y+1] = true;
                edge[x][y+1] = edge[x][y] + 1;
            }
        }
        
        if(map[x - 1][y] == 1 && x - 1 != -1){
            
            if(!check[x - 1][y]) {
                q.push(make_pair(x - 1, y));
                check[x - 1][y] = true;
                edge[x-1][y] = edge[x][y] + 1;
            }
        }
        
        if(map[x][y - 1] == 1 && y - 1 != -1){
            
            if(!check[x][y-1]) {
                q.push(make_pair(x, y - 1));
                check[x][y-1] = true;
                edge[x][y-1]  = edge[x][y] + 1;
            }
        }

    }


}

int main(){

for(int i = 0; i < 100; i++){
    for(int j = 0; j < 100; j++){
        check[i][j] = false;
    }
}

    int n, m;
    string s;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> s;

        for(int j = 0; j < m; j++){
            map[i][j] = s[j] - '0';
        }
    }

    N = n - 1; M = m - 1;
    
    bfs(0, 0);

    cout << edge[N][M];
}
