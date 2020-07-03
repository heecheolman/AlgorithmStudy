#include <iostream>
#include <deque>
#include <sstream>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    deque<int> q, reverseQ;
    int T, size;
    cin>>T;
    
    for(int i = 0 ; i < T ; i++){
        string fx, input,  output = "[", sub;
        bool error = false, r = false;

        cin>>fx;
        cin>>size;
        cin>>input;
        
        q.clear();
        
            sub = input.substr(1, input.size() - 2);
        
            istringstream ss(sub);
            string stringBuffer;
            while (getline(ss, stringBuffer, ','))
            {
                q.push_back(atoi(stringBuffer.c_str()));
            }

        
        for(int j = 0 ; j < fx.size() ; j++){
            
            if(fx[j] == 'D' && q.empty()){
                error = true;
                break;
            }
            
            else if(fx[j] == 'R'){
                
                r = !r;
                
            }
            else{
                if(r) q.pop_back();
                else q.pop_front();
            }
        }
        
        if(error) cout<<"error\n";
        
        else if(!q.empty()){
            if(r){
                    output +=  to_string(q.back());
                
                    for(long j = q.size() - 2 ; j >= 0 ; j--){
                        output += "," + to_string(q[j]);
                    }
                
                    output += "]";
                
                    cout<<output<<"\n";
            }else{
                
                output +=  to_string(q.front());
                
                for(int j = 1 ; j < q.size() ; j++){
                    output += "," + to_string(q[j]);
                }
                
                output += "]";
            
                cout<<output<<"\n";
            }
        }
        
        else{
            output += "]";
                    
            cout<<output<<"\n";
        }
    }
}
