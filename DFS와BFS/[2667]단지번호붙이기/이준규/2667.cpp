#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int map[25][25] = {0};
bool check[25][25];
vector<int> result;
int sum = 0;

void dfs(int a, int b){
    check[a][b] = true;
    sum++;

    if(map[a + 1][b] == 1 && a + 1 < 25){
        
        if(!check[a+1][b])
            dfs(a + 1, b);
    }
    
    if(map[a][b + 1] == 1 && b + 1 < 25){
        
        if(!check[a][b+1])
            dfs(a, b + 1);
    }
    
    if(map[a - 1][b] == 1 && a - 1 != -1){
        
        if(!check[a-1][b])
            dfs(a - 1, b);
    }
    
    if(map[a][b - 1] == 1 && b - 1 != -1){
        
        if(!check[a][b-1])
            dfs(a, b - 1);
    }

    

}

int main(){

for(int i = 0; i < 25; i++){
    for(int j = 0; j < 25; j++){
        check[i][j] = false;
    }
}

    int n, count = 0;
    string s;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> s;

        for(int j = 0; j < s.length(); j++){
            map[i][j] = s[j] - '0';
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j] == 1 && !check[i][j]){
                dfs(i, j);
                count++;
                result.push_back(sum);
                sum = 0;
            }
        }
    }

    cout << count << "\n";

    sort(result.begin(), result.end());

    for(int i = 0; i < result.size(); i++)
        cout << result[i] << "\n";
}
