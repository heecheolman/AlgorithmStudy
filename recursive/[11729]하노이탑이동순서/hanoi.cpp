#include <iostream>
using namespace std;

void hanoi(int n, int a, int b, int c){
    if(n == 1){
        cout<<a<<" "<<c<<"\n";
        return;
    }
    else{
        hanoi(n-1, a, c, b);
        cout<<a<<" "<<c<<"\n";
        hanoi(n-1, b, a, c);
    }
}

int main(){
    int n ,count=1;
    cin>>n;
    cout<< (1<<n) - 1 <<"\n";
    hanoi(n, 1, 2, 3);
}
