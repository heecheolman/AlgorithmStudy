#include <iostream>
#include <vector>
using namespace std;

int main(){
    int a,s=2, count=1;
    vector<int> myvector;
    cin>>a;
    if(a>=1&&a<=1000000000){
        for(int i=0;i<a;i++){
            myvector.push_back(i);
            if(myvector.size()>=s){
                s+= 6*count;
                count++;
            }
        }
        cout<<count;
    }
}

로 풀었다가 메모리 초과로 두번 까여서 다시품:
