#include <iostream>
#include <string>
#include <cstring>
#include <stack>
using namespace std;

int main(){
    int n;
    bool b;
    cin>>n;
    char a[50];
    stack<char> s;
    
    for(int i = 0 ; i < n ; i++){
        b = true;
        cin>>a ;
        
        if (strlen(a)&1) {
            b = false;
        }
        
        else {
            
                for(int j = 0 ; j < strlen(a) ; j++){
                    if(a[j] == '(') s.push(a[j]);
                    
                    else if(!s.empty()) {
                        s.pop();
                    }
                    else  {
                        b = false;
                        break;
                    }
            
                }
        }
        
        if(s.empty() && b) {
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
            while(!s.empty() )
            {
                s.pop( );
            }
        }
    }
}
