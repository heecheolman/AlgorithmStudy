#include <iostream>

using namespace std;

void sort (int arr[], int i) {
    int temp = 0;
    for (int j = 0; j < i; j++){
        for (int s = j + 1; s < i; s++) {
            if (arr[j] < arr[s]) {
                temp = arr[s];
                arr[s] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main () {
    int N = 0;
    cin >> N;

    int arr[10];
    int i = 0;

    while (N != 0) {
        arr[i++] = N % 10;
        N /= 10;
    }

    sort(arr, i);

    for (int j = 0; j < i; j++) {
        cout << arr[j];
    }
}