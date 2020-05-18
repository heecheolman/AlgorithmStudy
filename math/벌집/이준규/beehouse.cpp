#include <iostream>
using namespace std;

int main(){
    int n, count=0;
    cin>>n;
    for(int s = 2 ; s<=n ; count++)s+= 6 * count;
    if(n==1)count=1;
    cout<<count;
}
