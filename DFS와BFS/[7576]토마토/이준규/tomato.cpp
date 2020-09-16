#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int farm[1000][1000];
int x, y;
vector<pair<int, int>> v;
vector<pair<int, int>> q;

int tomato(){
    int count = -1;

    for(int i = 0; i < v.size(); i++){
        q.push_back(make_pair(v[i].first, v[i].second));
    }

    while(!q.empty()){
        int n = q.size();
        count++;

        for(int i = 0; i < n; i++){
            int a = q[i].first;
            int b = q[i].second;

            if(farm[a + 1][b] == 0 && a + 1 < y){
                farm[a + 1][b] = 1;
                q.push_back(make_pair(a + 1, b));
            }
            if(farm[a][b + 1] == 0 && b + 1 < x){
                farm[a][b + 1] = 1;
                q.push_back(make_pair(a, b + 1));
            }
            if(farm[a - 1][b] == 0 && a - 1 != -1){
                farm[a - 1][b] = 1;
                q.push_back(make_pair(a - 1, b));
            }
            if(farm[a][b - 1] == 0 && b - 1 != -1){
                farm[a][b - 1] = 1;
                q.push_back(make_pair(a, b - 1));
            }

        }

        reverse(q.begin(), q.end());
        for(int i = 0; i < n; i++){
            q.pop_back();

        }

        
    }

    return count;
}


int main(){

    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

for(int i = 0; i < 1000; i++){
    for(int j = 0; j < 1000; j++){
        farm[i][j] = -1;
    }
}

int input;

cin >> x >> y;

for(int i = 0; i < y; i++){
    for(int j = 0; j < x; j++){
        cin >> input;
        farm[i][j] = input;
    }
}

for(int i = 0; i < y; i++){
    for(int j = 0; j < x; j++){
        if(farm[i][j] == 1){
            v.push_back(make_pair(i, j));
        }
    }
}

int count = tomato();

bool b = false;

for(int i = 0; i < y; i++){
    for(int j = 0; j < x; j++){
        if(farm[i][j] == 0){
            b = true;
            break;
        }
    }
}

    if(b){
        cout << "-1";
    }else{
        cout << count++;
    }

}
