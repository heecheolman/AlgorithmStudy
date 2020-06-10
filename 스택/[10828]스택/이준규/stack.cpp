//사실 벡터를 이용하는게 깔끔하지만 날것의 것들로 풀어보고 싶었다.

#include <iostream>
#include <string>
using namespace std;

int main(){
    int n , a, count = 0;
    string str;
    cin>>n ;
    int stack[n]; // n 번을 푸시만 하더라도 공간이 허용
    int *p = stack;
    *p = -1; // 첫칸을 -1로 해버림

    cin.ignore(256,'\n'); //개행이 입력되면 버퍼를 비운다 그렇지 않으면 getline에 남아잇다

    for(int i = 0 ; i < n ; i++){
        getline(cin, str); // 공백을 포함해서 입력 받는 함수

        if(str.find("push")==0){// 푸시가 포함된 입력이면 "push "까지 자르고 뒤에 숫자만
            a = atoi(str.erase(0, 5).c_str());
            p++;
            *p = a;
        }
        
        else if(str == "pop"){
                if(*p == -1) cout<<*p<<"\n";
                else {
                    cout<<*p<<"\n";
                    p--;
                }
            }
            
        else if(str == "top"){
                    cout<<*p<<"\n";
        
            }
            
        else if(str == "size"){//pop이나 empty를해도 배열을 비우는개념이 아니라 포인터만 전칸으로 옮겨주는 거라서 배열의 크기를 못잼. 맨첫칸까지 칸수를 센 후 포인터 원상복귀
                while(*p != -1){
                    count++;
                    p--;
                }
                p += count;
                cout<<count<<"\n";
                count = 0;
            }
            
        else if(str == "empty"){//배열이 비엇는지 안비엇는지는 포인터카맨첫칸을 가르킬때로판단
                if(*p == -1) cout<<"1"<<"\n";
                else cout<<"0"<<"\n";
            }
        }
        
}
