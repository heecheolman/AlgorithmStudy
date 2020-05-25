#include <iostream>
using namespace std;

int nachi(int n){
    if(n == 1 || n == 0) return n;
    return nachi(n-2) + nachi(n-1);
}

int main(){
    int n;
    cin>>n;
    cout<<nachi(n);
}
