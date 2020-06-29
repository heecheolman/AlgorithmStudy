#include <iostream>
using namespace std;

    int n , front = 0, back = 0;


bool empty(){
    return (back == front);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    

    cin>>n;
    string str;
    int q[n];
    
    
    cin.ignore(256,'\n');

    for(int i = 0; i< n; i++){
        getline(cin, str);
        
        if(str == "pop"){
            if(empty()) cout<<"-1\n";
            else {
                cout<<q[front]<<"\n";
                front++;
            }
        }
        
        else if(str == "front"){
            if(empty()) cout<<"-1\n";
            else {
                cout<<q[front]<<"\n";
            }
            
        }
            
        else if(str == "size"){
            cout<<back - front<<"\n";
        }
        
        else if(str == "empty"){
            cout<<(back == front)<<"\n";
        }
            
        else if(str == "back"){
            if(empty()) cout<<"-1\n";
            else {
                cout<<q[back-1]<<"\n";
            }
        }
        
        else{
            q[back] = atoi(str.erase(0, 5).c_str());
            back++;
        }
    }
}
