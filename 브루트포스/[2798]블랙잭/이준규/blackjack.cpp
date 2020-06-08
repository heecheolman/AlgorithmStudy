#include <iostream>
using namespace std;

int main(){
    int n, m, temp = 0, max = 0;
    cin>>n>>m;
    int card[n];
    for( int i = 0 ; i < n ; i++){
        cin>>card[i];
    }
    
    for(int i=0; i< n;i++){
        for(int j=i+1; j< n; j++){
            for(int k=j+1; k<n; k++){
                temp = card[i]+card[j]+card[k];
                if(temp<=m && temp > max) max = temp;
            }
        }
    }
    
    cout<<max;
}
