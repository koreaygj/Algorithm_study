#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int coin[101] = {};
    int dp[10001] = {1, 0, };
    for(int i = 0; i < n; i++)
        cin >> coin[i];
    for(int i = 0; i < n; i++){
        for(int j = coin[i]; j <= k; j++){
            dp[j] += dp[j - coin[i]];
        }
    }
    cout << dp[k] << "\n";
}