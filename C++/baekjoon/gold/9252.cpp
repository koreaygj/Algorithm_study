#include <bits/stdc++.h>
using namespace std;
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    string first, second;
    int dp[1001][1001] = {0, };
    cin >> first;
    cin >> second;
    if(first.size() > second.size())
        swap(first, second);
    string ans = "";
    for(int i = 1; i <= first.size(); i++){
        for(int j = 1; j <= second.size(); j++){
            if(first[i - 1] == second[j - 1]){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int a = first.size();
    int b = second.size();
    while(a && b){
        if(dp[a - 1][b] == dp[a][b])
            a--;
        else if(dp[a][b - 1] == dp[a][b])
            b--;
        else{
            --a;
            --b;
            ans = first[a] + ans;
        }
    }
    cout << dp[first.size()][second.size()] << "\n";
    cout << ans << "\n";
    return 0;
}