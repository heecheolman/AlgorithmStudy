#include <iostream>
#include <cstring>
#include <string>
#include <stack>
using namespace std;

int main(){

    
            stack<char> s;
            bool b;
    string str;
    
    while(1){
            b = true;
            getline(cin, str);
            if(str == ".") break;
    
        
        for(int i = 0 ; i< str.length() ; i++){
            
            if(str[i] == '(' || str[i] == '['){
                s.push(str[i]);
            }
                
            else if(str[i]==')'){
                    if(!s.empty() && s.top() == '(') s.pop();
                    else{
                        b=false;
                        break;
                    }
            }
                
            else if(str[i] == ']'){
                    if(!s.empty() && s.top() == '[') s.pop();
                    else{
                        b=false;
                        break;
                    }
            }
        }
        
        if(s.empty() && b) cout<<"yes\n";
        else {
            cout<<"no\n";
            while(!s.empty()){
                s.pop();
            }
        }
    }
}

