#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, sum = 0, freq = 0, mode = 0;
    
    cin >> n;
    
    int arr[n], count[8001] = {0};
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        count[4000 + arr[i]]++;
        sum += arr[i];
    }
    
    sort(arr, arr + n);
    
    for(int i = 0; i < 8001; i++){
        if(freq < count[i]){
            freq = count[i];
            mode = i - 4000;
        }
    }
    
    for(int i = mode + 4001; i < 8001; i++){
        if(count[i] == freq){
            mode = i - 4000;
            break;
        }
    }
    
    cout << round((double)sum / n) << "\n";
    cout << arr[n / 2] << "\n";
    cout << mode << "\n";
    cout << arr[n - 1] - arr[0] << "\n";
}
