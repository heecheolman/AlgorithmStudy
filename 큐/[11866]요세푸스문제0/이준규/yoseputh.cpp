#include <iostream>
#include <deque>
using namespace std;


int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n, k;
    deque<int> q;
    string output = "<";
    
    cin>>n>>k;
    
    for(int i = 0 ; i < n ; i++){
        q.push_back(i+1);
    }
    
    while(q.size() != 1){
        for(int i = 0 ; i < k - 1 ; i++){
            q.push_back(q.front());
            q.pop_front();
        }
        output += to_string(q.front());
        output += ", ";
        q.pop_front();
    }
    output += to_string(q.front());
    output += ">";
    
    cout<<output;
}
