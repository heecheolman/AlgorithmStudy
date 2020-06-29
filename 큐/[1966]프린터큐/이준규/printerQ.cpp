#include <iostream>
#include <utility>
#include <deque>
using namespace std;


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int testcase, n, m, count;
    deque<pair<int, int>> q;
    cin>>testcase ;
    
    for(int i = 0 ; i < testcase ; i++){
        count = 1;
        q.clear();
        
        cin>>n>>m;
        
        int a[n];
        
        for(int j = 0 ; j < n ; j++){
            cin>>a[j];
            q.push_back(make_pair(j, a[j]));
        }
        
        while(1){
            
            int max = 0;
            
            for(int j = 0 ; j < q.size() ; j++){
                if(max < q[j].second){
                    max = q[j].second;
                }
            }
            
            while(q.front().second != max){
                q.push_back(q.front());
                q.pop_front();
            }
        
            if(q.front().first == m){
                cout<<count<<"\n";
                break;
            }
            else{
                q.pop_front();
                count++;
            }
            
        }

    }
    
}
