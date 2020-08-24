#include <iostream>
#include <vector>

using namespace std;

vector<int> pre, in;

void inorder(int s, int e){
    if(s > e)
        return;

    in.push_back(pre[s]);

    if(s == e)
        return;

    int index = s;

    for(int i = s + 1; i <= e; i++){
        if(pre[s] < pre[i]){
            index = i;
            break;
        }
    }

    if(index == s){
        inorder(s + 1, e);
    }

    else{
        inorder(index, e);

        inorder(s+1, index - 1);
    }


}


int main(){
    int a;

    while(cin >> a){
        pre.push_back(a);
    }

    int start = 0, end = pre.size() - 1;

    inorder(start, end);

    for(int i = in.size() - 1; i >= 0; i--){
        cout << in[i] << "\n";
    }

}
