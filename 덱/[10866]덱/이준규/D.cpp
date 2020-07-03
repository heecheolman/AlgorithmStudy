#include <iostream>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N , back = 0, front = 0, size = 0, push;
    string str;
    cin>>N;
    int a[N];
    
    for(int i = 0 ; i < N ; i++){
        cin>>str;
        
        if(str == "size"){
            cout<<size<<"\n";
        }
        else if(str == "empty"){
            if(back == front && size == 0) cout<<"1\n";
            else cout<<"0\n";
        }
        else if(str == "front"){
            if(size == 0) cout<<"-1\n";
            else cout<<a[front]<<"\n";
        }
        else if(str == "back"){
            if(size == 0) cout<<"-1\n";
            else if(back == 0) cout<<a[N-1]<<"\n";
            else cout<<a[back-1]<<"\n";
        }
        else if(str == "pop_front"){
            if(size == 0) cout<<"-1\n";
            else{
                size--;
                cout<<a[front]<<"\n";
                front = (front + 1) % N;
            }
        }
        else if(str == "pop_back"){
            if(size == 0) cout<<"-1\n";
            else{
                size--;
                if(back == 0){
                    cout<<a[N-1]<<"\n";
                    back = N-1;
                }
                else {
                    cout<<a[back - 1]<<"\n";
                    back--;
                }
            }
        }
        else if(!str.find("push_back")){
            size++;
            cin>>push;
            a[back] = push;
            back = (back+1) % N;
        }
        else if(!str.find("push_front")){
            size++;
            cin>>push;
            if(front == 0){
                a[N-1] = push;
                front = N-1;
            }
            else{
                front--;
                a[front] = push;
            }
        }
        
    }
}
