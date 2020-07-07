#include <iostream>

using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, temp;
    int arr[10001] = {0};
    
    cin >> n;
        
    for(int i = 0; i < n; i++){
        cin >> temp;
        arr[temp]++;
    }
        
    for(int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++){
        if(arr[i] != 0){
            for(int j = 0; j < arr[i]; j++){
                cout << i << "\n";
            }
        }
    }
}
