#include <iostream>
#include <queue>
using namespace std;

struct crush
{
    int x;
    int y;
    int b;
};


int map[1001][1001] ;
int depth[1001][1001][2] = {0, };
int a, b;
queue<crush> q;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

int bfs(){

    if(a == b && a == 1){
        return 1;
    }
    
    depth[0][0][0] = 1;

    crush tuple; tuple.x = 0; tuple.y = 0; tuple.b = 0;

    q.push(tuple);

    while(!q.empty()){
        int row = q.front().x;
        int cal = q.front().y;
        int bb = q.front().b;
        q.pop();

        for(int i = 0; i < 4; i++){
            
            
            if(row + dx[i] < a
            && cal + dy[i] < b
            && row + dx[i] != -1
            && cal + dy[i] != -1
            && depth[row + dx[i]][cal + dy[i]][bb] == 0
            ){
                if(a - 1 == row + dx[i] && b - 1 == cal + dy[i])
                    return depth[row][cal][bb] + 1;

                if(bb && map[row + dx[i]][cal + dy[i]] == 1) continue;

                crush pp; 
                pp.x = row + dx[i]; 
                pp.y = cal + dy[i]; 
                pp.b = bb;

                if(map[row + dx[i]][cal + dy[i]] == 0){
                    depth[row + dx[i]][cal + dy[i]][bb] = depth[row][cal][bb] + 1;
                    q.push(pp);
                }else if(map[row + dx[i]][cal + dy[i]] == 1 && !bb){
                    depth[row + dx[i]][cal + dy[i]][1] = depth[row][cal][bb] + 1;
                    pp.b = 1;
                    q.push(pp);
                }
                

            }



        }

    }

    return -1;

}

int main(){

    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    string s;

    cin >> a >> b;


    for(int i = 0; i < a; i++){
        cin >> s;
        for(int j = 0; j < b; j++){
            map[i][j] = s[j] - '0';
        }
    }

    cout << bfs();

    
}
