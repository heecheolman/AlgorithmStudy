#include <iostream>
#include <string>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, count = 0;
    cin>>n;
    
    for(int i = 666 ; i < n*1000 ; i++){
        if(to_string(i).find("666") != -1) count++;
        if(count == n){
            cout<<i;
            break;
        }
    }
}
