#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
string solution(string str, string bomb){
    int st_sz = str.size();
    int bomb_sz = bomb.size();
    string ans = "";
    for(int i = 0; i < st_sz; i++){
        ans += str[i];
        if(ans[ans.size() - 1] == bomb[bomb_sz - 1]){
            if(ans.size() >= bomb_sz){
                int cnt = 0;
                for(int j = bomb_sz - 1; j >= 0; j--){
                    if(ans[ans.size() - (bomb_sz - j)] == bomb[j])
                        cnt++;
                    else
                        break;
                }
                if(cnt == bomb_sz){
                    for(int j = 0; j < bomb_sz; j++){
                        ans.pop_back();
                    }
                }
            }
        }
    }
    if(ans == "")
        return "FRULA";
    return ans;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    string s;
    string bomb;
    cin >> s;
    cin >> bomb;
    cout << solution(s, bomb) << "\n";
}