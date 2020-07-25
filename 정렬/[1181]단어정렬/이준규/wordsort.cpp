#include<iostream>

using namespace std;

#define endl "\n"

int main()
{
    int n, min;
    
    cin >> n;
    
    string str[n];
    
    for(int i = 0; i < n; i++){
        cin >> str[i];
    }
    
    for(int i = 0; i < n - 1; i++){
        min = i;

        for(int j = i + 1; j < n; j++){
            if(str[j].length() == str[min].length()){
                if(str[j] < str[min]){
                    min = j;
                }
            }else if(str[j].length() < str[min].length()){
                min = j;
            }
        }

        swap(str[min], str[i]);
    }
    
    
    for(int i = 0; i < n; i++){
        if(str[i] != str[i - 1]){
            cout << str[i] << endl;
        }
    }
}
