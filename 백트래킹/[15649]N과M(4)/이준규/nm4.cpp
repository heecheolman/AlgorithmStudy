#include <iostream>
using namespace std;

int n , m;
int arr[9] = {0};


void back(int num, int a){


    if(a == m){
        for(int i = 0; i < m; i++){
            cout << arr[i] <<" ";
        }
        cout <<"\n";
        return ;
    }
    
    for(int i = num; i <= n; i++){
        arr[a] = i;
        back(i ,  a + 1);
    }
    
}

int main(){

    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);


    cin >> n >> m;

    back(1, 0);
}
