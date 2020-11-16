#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    vector<string> uid;
    map <string, string> name;
    stringstream ss;
    string a, b, c;

    for(int i = 0; i < record.size(); i++){
        ss.str(record[i]);
        ss >> a;
        if(a == "Enter"){
            ss >> b;
            ss >> c;

            answer.push_back("님이 들어왔습니다.");
            uid.push_back(b);
            name[b] = c;
        }
        else if(a == "Leave"){
            ss >> b;
            
            answer.push_back("님이 나갔습니다.");
            uid.push_back(b);
        }else{
            ss >> b;
            ss >> c;
            name[b] = c;
        }
        
        ss.clear();
    }

    for(int i = 0; i < answer.size(); i++){
        answer[i] = name[uid[i]] + answer[i];
    }

    return answer;
}
