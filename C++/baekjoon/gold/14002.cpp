#include <bits/stdc++.h>
using namespace std;
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    int arr[1001];
    int dp[1001];
    memset(arr, 0, sizeof(arr));
    memset(dp, 0, sizeof(dp));
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    dp[1] = 1;
    int ans = 1;
    vector<int> LIS;
    for(int i = 2; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= i; j++){
            if(arr[j] < arr[i]){
                if(cnt < dp[j])
                    cnt = dp[j];
            }
        }
        dp[i] = cnt + 1;
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
    for(int i = n; i > 0; i--){
        if(dp[i] == ans){
            LIS.push_back(arr[i]);
            ans--;
        }
    }
    sort(LIS.begin(), LIS.end());
    for(int out: LIS)
        cout << out << " ";
    cout << "\n";
}