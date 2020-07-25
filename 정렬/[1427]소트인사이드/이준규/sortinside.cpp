#include<iostream>

using namespace std;

#define endl "\n"


int main()
{
    int n, data[10] = {0}, a = 0, max = 0, len = 0;
    
    cin >> n;
    
    for(int i = 1; n / i != 0; i *= 10){
        data[a] = (n / i) - 10 * (n / (i * 10));
        a++;
        len++;
    }
    
    for(int i = 0; i < 9; i++){
        max = i;
        
        for(int j = i + 1; j < 10; j++){
            if(data[j] > data[max])  max = j;
        }
        
        if(i != max){
            swap(data[i], data[max]);
        }
    }
    
    for(int i = 0; i < len; i++){
        cout << data[i];
    }
}

