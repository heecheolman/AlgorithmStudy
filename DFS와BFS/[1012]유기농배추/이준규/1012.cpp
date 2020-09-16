#include <iostream>
using namespace std;

int farm[50][50];
int N, M;
bool visited[50][50];

void dfs(int a, int b){
    visited[a][b] = true;

    if(farm[a + 1][b] == 1 && a + 1 < N){
        
        if(!visited[a+1][b])
            dfs(a + 1, b);
    }
    
    if(farm[a][b + 1] == 1 && b + 1 < M){
        
        if(!visited[a][b+1])
            dfs(a, b + 1);
    }
    
    if(farm[a - 1][b] == 1 && a - 1 != -1){
        
        if(!visited[a-1][b])
            dfs(a - 1, b);
    }
    
    if(farm[a][b - 1] == 1 && b - 1 != -1){
        
        if(!visited[a][b-1])
            dfs(a, b - 1);
    }

    

}

int main(){

int T, K, x, y, count = 0;

cin >> T;

for(int i = 0; i < T; i++){
    for(int a = 0; a < 50; a++){
        for(int b = 0; b < 50; b++){
            farm[a][b] = 0;
            visited[a][b] = false;
        }
    }


    cin >> M >> N >> K;

    for(int j = 0; j < K; j++){
        cin >> x >> y;

        farm[y][x] = 1;
    }

    for(int k = 0; k < N; k++){
        for(int a = 0; a < M; a++){
            if(farm[k][a] == 1 && !visited[k][a]){
                dfs(k, a);
                count++;
            }
        }
    }

    cout << count << "\n";
    count = 0;

}

}
