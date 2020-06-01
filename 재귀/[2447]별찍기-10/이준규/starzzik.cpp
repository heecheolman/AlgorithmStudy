#include <iostream>
using namespace std;

char skrt[2187][2187];

void cho(){
    for(int i = 0;i<2187 ; i++){
        for(int j =0; j<2187; j++) {
            skrt[i][j] = ' ';
        }
    }
}

void star (int n, int x, int y){
    if(n ==1 ){
        skrt[x][y] = '*';
        return;
    }
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if(i != 1 || j != 1){
                star(n/3,n/3*i + x,n/3*j + y);
            }
        }
    }
}

int main(){
    int n;
    cho();
    cin>>n;
    
    star(n,0,0);
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < n ; j++){
            cout<<skrt[i][j];
        }
        cout<<endl;
    }
}
