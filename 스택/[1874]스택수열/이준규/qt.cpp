#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    int n, co = 0, j = 0;
    cin>>n;
    
    int a[n], b[n];
    
    stack<int> s;
    string output ="";
    
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    
    copy(a, a+n, b);
    sort(a, a+n);
    
   for(int i = 0 ; i < 2*n  ; i++){
        if(!s.empty() && s.top() == b[co]){
            s.pop();
            output += "-\n";
            if(s.empty() && co == n-1) break;
            co++;
            j--;
        }
        else{
            s.push(a[j]);
            output += "+\n";
        }
       j++;
    }
    
    if(co != n-1) cout<<"NO";
    else cout<<output;
}
