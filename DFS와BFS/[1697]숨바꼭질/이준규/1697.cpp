#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[100001];
int val[100001] = {0, };
queue<int> q;

void bfs(int a){

    q.push(a);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int i = 0; i < graph[x].size(); i++){

            if(val[graph[x][i]] == 0 && graph[x][i] >= x - 1){

                q.push(graph[x][i]);
                val[graph[x][i]] = val[x] + 1;

            }
        }

    }

}

int main(){

    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int a, b;

    cin >> a >> b;

    if(a == b)
        cout << 0;
    else if( a > b)
        cout << a - b;

        

    else{


        for(int i = 1; i <= b; i++){

            graph[i - 1].push_back(i);
            graph[i].push_back(i - 1);
        
            if(i * 2 < 100001){
                graph[i * 2].push_back(i);
                graph[i].push_back(i * 2);
            }
            
            if(i + 1 < 100001){
                graph[i].push_back(i + 1);
                graph[i + 1].push_back(i);
            }

        }

        bfs(a);

        cout << val[b];

    }
    
}
