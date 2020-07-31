#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool compare (string str, string str2) {
    int a = str.size();
    int b = str2.size();
    if (a == b) {
        return str < str2;
    }
    return a < b;
}

int main () {
    int N;
    cin >> N;
    
    string str[N];
    string temp;

    for (int i = 0; i < N; i++) {
        cin >> str[i];
    }

    //길이, 사전순으로 정렬
    sort(str, str + N, compare);

    for (int i = 0; i < N; i++) {
        if (i == 0) {
            cout << str[i] << "\n";
            temp = str[i];
        }
        if (i > 0 && str[i] != temp) {
            cout << str[i] << "\n";
            temp = str[i];
        }
    }
}