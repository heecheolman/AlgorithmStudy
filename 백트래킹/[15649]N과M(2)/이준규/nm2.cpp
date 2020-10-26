#include <iostream>

using namespace std;

int n , m;
int arr[9] = {0};
bool visit[9] = {false};


void back(int num, int a){
    if(a == m){
        for(int i = 0; i < m; i++){
            cout << arr[i] <<" ";
        }
        cout <<"\n";

        return ;
    }
    
    for(int i = num; i <= n; i++){

        if(!visit[i]){
            visit[i] = true;
            arr[a] = i;
            back( i + 1, a + 1);
            visit[i] = false;
        }
    }
    
}

int main(){

    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);


    cin >> n >> m;

    back(1, 0);
}
