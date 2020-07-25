#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

#define endl "\n"

bool compare(pair<string, int> a, pair<string, int> b){
    int a_age_index = (int)a.first.find(" ");
    int b_age_index = (int)b.first.find(" ");
    
    int a_age = atoi(a.first.substr(0, a_age_index).c_str());
    int b_age = atoi(b.first.substr(0, b_age_index).c_str());

    if(a_age == b_age){
        return a.second < b.second ;
    }
    
    return a_age < b_age ;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n;
    string str;
    
    cin >> n;
    
    pair<string, int> age[n];

    cin.ignore(256,'\n');
    
    for(int i = 0; i < n; i++){
        getline(cin, str);
        age[i] = make_pair(str, i);
    }
    
    sort(age, age + n, compare);
    
    for(int i = 0; i < n; i++){
        cout << age[i].first << endl;
    }
}
