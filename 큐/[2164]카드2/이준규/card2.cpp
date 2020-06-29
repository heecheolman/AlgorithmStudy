#include <iostream>
#include <deque>
using namespace std;


int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n;
    deque<int> q;
    
    cin>>n;
    
    for(int i = 0 ; i < n ; i++){
        q.push_back(i+1);
    }
    
    while(q.size() != 1){
        q.pop_front();
        
        if(q.size() == 1) break;
        
        q.push_back(q.front());
        q.pop_front();
    }
    cout<<q.front();
}
