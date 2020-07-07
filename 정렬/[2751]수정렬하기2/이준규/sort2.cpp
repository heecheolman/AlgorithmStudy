// sort 내장함수 사용

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n;
    
    cin >> n;
    
    int arr[n];
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    
    for(int i = 0; i < n; i++){
        cout << arr[i] << "\n";
    }
}
