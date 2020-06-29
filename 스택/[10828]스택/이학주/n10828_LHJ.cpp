#include <iostream>

using namespace std;

struct Stack{

    int data[1000];
    int size;

    //생성자: 멤버 변수를 초기화 시켜준다. 이걸 안하면 에러가 뜬다고 한다.
    Stack() {
        size = 0;
    }

    void push (int value){
        data[size] = value;
        size++;
    }

    int pop(){
        if(size == 0){
            return -1;
        }
        else{
            size--;
            return data[size];
        }
    }

    bool empty(){
        if(size == 0){
            return true;
        }
        else{
            return false;
        }
    }

    int top(){
        if(size == 0){
            return -1;
        }
        else{
            return data[size-1];
        }
    }
};

int main(void){
    
    ios::sync_with_stdio(false);

    int N;
    Stack stack;

    cin >> N;

    while(N--){
        string str;
        cin >> str;
        
        if(str == "push"){
            int inValue;
            cin >> inValue;
            stack.push(inValue);
        }
        else if(str == "pop"){
            cout << stack.pop() << endl;
        }
        else if(str == "empty"){
            cout << stack.empty() << endl;
        }
        else if(str == "size"){
            cout << stack.size << endl;
        }
        else if(str == "top"){
            cout << stack.top() << endl;
        }
    }

}