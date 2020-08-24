#include <iostream>
#include <vector>

using namespace std;

vector<int> in, post;

void findpre(int si, int ei, int sp, int ep){
    if(ep < sp && ei < si){
        return;
    }

    cout << post[ep] << " ";

    int index;

    for(int i = si; i <= ei; i++){
        if(in[i] == post[ep])
            index = i - si;
    }


    if(index == 0){

        findpre(si + index + 1, ei, sp + index, ep - 1);
        
    }else if(index == ei){

        findpre(si, si + index - 1, sp, sp + index - 1);

    }else{
        
        findpre(si, si + index - 1, sp, sp + index - 1);

        findpre(si + index + 1, ei, sp + index, ep - 1);

    }

}

int main(){
    int n, a;

    cin >> n;

    
        for(int j = 0; j < n; j++){
            cin >> a;
            in.push_back(a);
        }
        for(int j = 0; j < n; j++){
            cin >> a;
            post.push_back(a);
        }

    int start_in = 0;
    int end_in = in.size() - 1;
    int start_post = 0;
    int end_post = post.size() - 1;
    
    findpre(start_in, end_in, start_post, end_post);

}
