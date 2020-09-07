#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string s;
    vector<int> v , temp;
    vector<char> x;
    bool b = true;
    int index = 0 , result = 0, answer = 0;

    cin >> s;

    for(int i = 0; i < s.length(); i++){      //부호와 숫자를 나눠담는파트
        if(s[i] == '-'){
            v.push_back(atoi(s.substr(index, i).c_str()));
            x.push_back('-');
            index = i + 1;
        }else if(s[i] == '+'){
            v.push_back(atoi(s.substr(index, i).c_str()));
            x.push_back('+');
            index = i + 1;
        }
    }
    v.push_back(atoi(s.substr(index, s.length()).c_str()));

    

    for(int i = 0; i < x.size(); i++){  // + 계산 먼저 해서 새로운 벡터에 담기
        if(x[i] == '+'){
            result += v[i];

            if(i == x.size() - 1){
                result += v[i + 1];
                temp.push_back(result);
                b = false;
                break;
            }
        }else{
            result += v[i];
            temp.push_back(result);
            result = 0;
        }
    }
    
    if(b) temp.push_back(v.back());       //마지막 부호가 + 인 경우를 체크하기위한 b


    answer += temp[0];

    for(int i = 1; i < temp.size(); i++){ // 첫 숫자부터 쭈욱 빼기
        answer -= temp[i];
    }

    cout << answer;

}
//   +    -    +    +   -    +    -      -
//60   55   50   40   30  40   20    35     20
