#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {

    int answer = 0;
    vector<string> v1, v2;

    for(int i = 0; i <= str1.length() - 2; i++){
        if(!isalpha(str1[i]) || !isalpha(str1[i + 1]))
            continue;
        else{
            string zz = "";
            zz += toupper(str1[i]);
            zz += toupper(str1[i + 1]);
            v1.push_back(zz);
        }
    }

    for(int i = 0; i <= str2.length() - 2; i++){
        if(!isalpha(str2[i]) || !isalpha(str2[i + 1]))
            continue;
        else{
            string zz = "";
            zz += toupper(str2[i]);
            zz += toupper(str2[i + 1]);
            v2.push_back(zz);
        }
    }

    if(v1.empty() && v2.empty())
        return 65536;

    int count = 0;


    for(int i = 0; i < v1.size(); i++){
        for(int j = 0; j < v2.size(); j++){
            if(v1[i] == v2[j]){
                count++;
                v2[j] = "sss";
                break;
            }
        }
    }


    int hap = v1.size() + v2.size() - count;

    count *= 65536;

    answer =  count / hap;

    return answer;
}
