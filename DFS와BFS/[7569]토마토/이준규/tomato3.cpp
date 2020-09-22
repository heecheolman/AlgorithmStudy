#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct loca
{
    int x, y, z;
};

int farm[100][100][100];
int x, y, z;
vector<loca> v;
queue<loca> q;

int dz[6] = {0, 0, 0, 0, 1, -1};
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};


int tomato(){
    int count = -1;

    for(int i = 0; i < v.size(); i++){
        q.push(v[i]);
    }

    while(!q.empty()){
        int n = q.size();
        count++;

        for(int i = 0; i < n; i++){
            int a = q.front().z;
            int b = q.front().x;
            int c = q.front().y;

            q.pop();

            loca temp;

            for(int j = 0; j < 6; j++){
                if(a + dz[j] < z
                && b + dx[j] < y
                && c + dy[j] < x
                && a + dz[j] != -1
                && b + dx[j] != -1
                && c + dy[j] != -1
                && farm[a + dz[j]][b + dx[j]][c + dy[j]] == 0
                ){
                    farm[a + dz[j]][b + dx[j]][c + dy[j]] = 1;
                    temp.z = a + dz[j];
                    temp.x = b + dx[j];
                    temp.y = c + dy[j];
                    q.push(temp);
                }
            }
            

        }

        
    }

    return count;
}


int main(){

    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

for(int i = 0; i < 100; i++){
    for(int j = 0; j < 100; j++){
        for(int k = 0; k < 100; k++){
            farm[k][i][j] = -1;
        }
    }
}

int input;

cin >> x >> y >> z;

for(int k = 0; k < z; k++){
    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            cin >> input;
            farm[k][i][j] = input;
        }
    }
}



for(int k = 0; k < z; k++){
    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            if(farm[k][i][j] == 1){
                loca l;
                l.x = i;
                l.y = j;
                l.z = k;
                v.push_back(l);
            }
        }
    }
}

int count = tomato();

bool b = false;

for(int k = 0; k < z; k++){
    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            if(farm[k][i][j] == 0){
                b = true;
                break;
            }
        }
    }
}

    if(b){
        cout << "-1";
    }else{
        cout << count;
    }

}
