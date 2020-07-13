#include <iostream>

using namespace std;

int main () {
    int N = 0;
    cin >> N;
    int list[N];
    int temp = 0;

    for (int i = 0; i < N; i++) {
        cin >> list[i];
    }

    for (int j = 0; j < N; j++) {
        for (int s = j + 1; s < N; s++) {
            if (list[j] > list[s]) {
                temp = list[s];
                list[s] = list[j];
                list[j] = temp;
            }
        }
    }

    for (int k = 0; k < N; k++) {
        cout << list[k] << "\n";
    }
}