#include <iostream>
using namespace std;

int main(){
    int n, count = 1;
    cin>>n;
    int a[n], b[n];
    for(int i = 0 ; i < n ; i++){
        cin>>a[i]>>b[i];
    }
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(a[i]<a[j] && b[i]<b[j]) count++;
        }
        cout<<count<<" ";
        count = 1;
    }
}
