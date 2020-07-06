#include <iostream>

using namespace std;

struct Deque
{
    int N;
    int start;
    int end;

    Deque(){
        cin >> N;
        start = N - 1;
        end = N;
    }

    int data[20000];

    void push_front(int value){
        data[start] = value;
        start--;
    }

    void push_back(int value){
        data[end] = value;
        end++;
    }

    int size(){
        return end - start - 1;
    }

    bool empty(){
        if(size() == 0){
            return true;
        }
        else{
            return false;
        }
    }

    int pop_front(){

        if( empty() ){
            return -1;
        }
        else{
            start++;
            return data[start];
            data[start] = 0;
        }
    }

    int pop_back(){

        if( empty() ){
            return -1;
        }
        else{
            end--;
            return data[end];
            data[end] = 0;
        }
    }

    int front(){
        if( empty() ){
            return -1;
        }
        else{
            return data[start + 1];
        }
    }

    int back(){
        if( empty() ){
            return -1;
        }
        else{
            return data[end - 1];
        }
    }

};


int main(){

    cin.tie(0);
    cin.sync_with_stdio(0);

    Deque deque;

    while(deque.N--){
        string str;
        cin >> str;

        if(str == "push_front"){
            int inValue;
            cin >> inValue;
            deque.push_front(inValue);
        }
        else if(str == "push_back"){
            int inValue;
            cin >> inValue;
            deque.push_back(inValue);
        }
        else if(str == "size"){
            cout << deque.size() << "\n";
        }
        else if(str == "empty"){
            cout << deque.empty() << "\n";
        }
        else if(str == "pop_front"){
            cout << deque.pop_front() << "\n";
        }
        else if(str == "pop_back"){
            cout << deque.pop_back() << "\n";
        }
        else if(str == "front"){
            cout << deque.front() << "\n";
        }
        else if(str == "back"){
            cout << deque.back() << "\n";
        }
        
    }
}