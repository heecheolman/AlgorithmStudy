#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    deque<int> q;
    int n , m, temp, count = 0, tempindex = 0;
    
    cin>>n>>m;
    
    for(int i = 0 ; i < n ; i++){
        q.push_back(i+1);
    }
    
    for(int i = 0 ; i < m ; i++){
        cin>>temp;
        
        if(q.front() != temp){
            
            for(int k = 0 ; k < q.size() ; k++){
                if(q[k] == temp) tempindex = k+1;
            }
            
            if(tempindex > ceil((double)q.size()/2)){
                for(int j = 0 ; j <= (q.size()-tempindex) ; j++){
                    q.push_front(q.back());
                    q.pop_back();
                    count++;
                }
            }
            else{
                for(int j = 0 ; j < (tempindex-1) ; j++){
                    q.push_back(q.front());
                    q.pop_front();
                    count++;
                }
            }
        }
        
        q.pop_front();
    }
    cout<<count;
}
