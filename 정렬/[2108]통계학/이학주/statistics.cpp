#include <iostream>

using namespace std;

int average (int list[], int N) {
    int sum = 0;
    int avg = 0;
    for (int i = 0; i < N; i++) {
        sum += list[i];
    }
    avg = sum / N;
    return avg;
}

int mid (int list[], int N) {
    int center = 0;
    int temp = 0;
    for (int j = 0; j < N; j++) {
        for (int s = j + 1; s < N; s++) {
            if (list[j] > list[s]) {
                temp = list[s];
                list[s] = list[j];
                list[j] = temp;
            }
        }
    }
    center = N / 2;
    return list[center];
}

int frequency (int list[], int N, int count[], int output) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (list[i] == list[j]) {
                count[i]++;
            }
        }
    }

    int max = 0;

    for (int i = 1; i < N; i++) {
        if (count[i] > count[i - 1]) {
            output = list[i];
        }
        if (count[i] == count[i - 1]) {
            
        }
    }
    
    return output;
}

int range (int list[], int N) {
    int max = list[0];
    int min = list[0];
    for (int i = 1; i < N; i++) {
        if (max < list[i]) {
            max = list[i];
        }
        if (min > list[i]) {
            min = list[i];
        }
    }
    return max - min;
}

int main () {
    int N = 0;
    cin >> N;
    int list[N];
    int count[N];
    int output;

    for (int i = 0; i < N; i++) {
        cin >> list[i];
    }

    cout<< average(list, N) << "\n";
    cout<< mid(list, N) << "\n";
    cout<< frequency(list, N, count, output) << "\n";
    cout<< range(list, N) << "\n";
}