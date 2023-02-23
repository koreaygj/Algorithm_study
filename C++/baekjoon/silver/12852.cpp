#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;
int dp[1000001];
void graph(int n, int cnt){
    if(cnt <= n){
        if(cnt % 6 == 0)
            dp[cnt] = min(dp[cnt - 1], min(dp[cnt / 2], dp[cnt / 3])) + 1;
        else if(cnt % 2 == 0)
            dp[cnt] = min(dp[cnt - 1], dp[cnt / 2]) + 1;
        else if(cnt % 3 == 0)
            dp[cnt] = min(dp[cnt - 1], dp[cnt / 3]) + 1;
        else
            dp[cnt] = dp[cnt - 1] + 1;
        graph(n, cnt + 1);
    }
    if(cnt == 2)
        return;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    if(n == 1)
        dp[1] = 0;
    else
        graph(n, 2);
    cout << dp[n] << "\n";
    while(n > 1){
        cout << n << " ";
        if(dp[n] == dp[n - 1] + 1)
            n--;
        else if(n % 2 == 0 && dp[n] == dp[n / 2] + 1)
            n /= 2;
        else if(n % 3 == 0 && dp[n] == dp[n / 3] + 1)
            n /= 3;
    }
    cout << "1\n";
    return 0;
}