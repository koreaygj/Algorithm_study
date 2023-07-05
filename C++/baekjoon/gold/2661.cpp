#include <bits/stdc++.h>
using namespace std;
string ans;
vector<int> result;
int first = 0;
void dfs(int n, int cnt){
    if(first > 1)
        return;
    if(n == cnt){
        if(first < 1)
            cout << ans << "\n";
        first++;
        return;
    }
    for(int i = 1; i <= 3; i++){
        if(ans[cnt - 1] == char(i + 48))
            continue;
        ans += to_string(i);
        int index = 0;
        bool flag = false;
        for(int j = cnt - 2; j >= 0; j--){
            if(ans[j] == char(i + 48)){
                index = j;
                int st_size = ans.size() - index - 1;
                if(index - st_size + 1 < 0)
                    break;
                if(ans.substr(index + 1, st_size) == ans.substr(index - st_size + 1, st_size)){
                    flag = true;
                    continue;
                }
            }
        }
        if(!flag)
            dfs(n, cnt + 1);
        ans = ans.substr(0, ans.size() - 1);
    }
    return;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < 3; i++){
        ans = to_string(i + 1);
        dfs(n, 1);
        ans = "";
    }
}