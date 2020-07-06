#include <iostream>
#include <deque>

using namespace std;

int main(){

    cin.tie(0);
    cin.sync_with_stdio(0);

    int output = 0;
    int N;
    int M;

    cin >> N;
    cin >> M;

    deque <int> dq;

    for(int i = 0; i < N; i++){
        dq.push_back(i + 1);
    }

    while(M--){
        int okgo;
        cin >> okgo;

        for (int i = 0; i < dq.size(); i++)
        {
            if (okgo == dq[i]){

                if(i < dq.size() - i){
                    output += i;
                    
                    while (i--)
                    {
                        dq.push_back(dq.front());
                        dq.pop_front();
                    }
                }
                else if(i >= dq.size() - i){
                    output += dq.size() - i;

                    int count = dq.size() - i;
                    while (count--)
                    {
                        dq.push_front(dq.back());
                        dq.pop_back();
                    }
                }
                dq.pop_front();
            }
        }
    }

    cout << output;

}